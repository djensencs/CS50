// Helper functions for music

#include <cs50.h>
#include <math.h>
#include <string.h>
#include <stdio.h>

#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    // convert to integers
    int numerator = fraction[0] - '0';
    int denominator = fraction[2] - '0';

    // converts the denominator into number of eighths
    return (8 / denominator) * numerator;
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    // Get octave from the last char in note string
    int octave = note[strlen(note) - 1] - '0';

    // Determine Frequency ot note in the given octave
    double freq = 0.0;

    if (note[0] == 'A')
    {
        freq = 440;
    }
    else if (note[0] == 'B')
    {

        freq = 440 * (pow(2.0, (2.0 / 12.0)));
    }
    // following notes below A4 so 2^(-n/12) so we 440/2^(n/12)
    else if (note[0] == 'C')
    {
        freq = 440.0 / (pow(2.0, (9.0 / 12.0)));
    }
    else if (note[0] == 'D')
    {
        freq = 440.0 / (pow(2.0, (7.0 / 12.0)));
    }
    else if (note[0] == 'E')
    {
        freq = 440.0 / (pow(2.0, (5.0 / 12.0)));
    }
    else if (note[0] == 'F')
    {
        freq = 440.0 / (pow(2.0, (4.0 / 12.0)));
    }
    else if (note[0] == 'G')
    {
        freq = 440.0 / (pow(2.0, (2.0 / 12.0)));
    }


    // Loop to shift octave
    if (octave > 4)
    {
        for (int i = 0; i < octave - 4; i++)
        {
            freq *= 2.0;
        }
    }
    else if (octave < 4)
    {
        for (int i = 0; i < 4 - octave; i++)
        {
            freq /= 2.0;
        }
    }

    // Adjustment or flat or sharp
    if (note[1] == 'b')
    {
        freq /= (pow(2.0, (1.0 / 12.0)));
    }
    else if (note[1] == '#')
    {
        freq *= (pow(2.0, (1.0 / 12.0)));
    }

    // Return frequency value as int
    int result = round(freq);
    return result;
}



// Determines whether a string represents a rest
bool is_rest(string s)
{
    if (s[0] == '\0')
    {
        return true;
    }
    else
    {
        return false;
    }
}
