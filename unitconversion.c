#include <stdio.h>
#include <stdlib.h>

// Function to convert temperature from Celsius to Fahrenheit
double convertCelsiusToFahrenheit(double celsiusTemperature)
{
    return (celsiusTemperature * 9 / 5.0) + 32;
}

// Function to convert temperature from Fahrenheit to Celsius
double convertFahrenheitToCelsius(double fahrenheitTemperature)
{
    return (fahrenheitTemperature - 32) * 5.0 / 9;
}

// Function to convert temperature from Celsius to Kelvin
double convertCelsiusToKelvin(double celsiusTemperature)
{
    return celsiusTemperature + 273.15;
}

// Function to convert temperature from Kelvin to Celsius
double convertKelvinToCelsius(double kelvinTemperature)
{
    return kelvinTemperature - 273.15;
}

// Function to convert temperature from Celsius to Rankine
double convertCelsiusToRankine(double celsiusTemperature)
{
    return (celsiusTemperature + 273.15) * 9.0 / 5;
}

// Function to convert temperature from Rankine to Celsius
double convertRankineToCelsius(double rankineTemperature)
{
    return (rankineTemperature * 5.0 / 9) - 273.15;
}

// Function to convert temperature between different units
double unitConverter(int temperature, char current_unit, char required_unit)
{
    if (current_unit == 'C')
    {
        if (required_unit == 'F')
        {
            return convertCelsiusToFahrenheit(temperature);
        }
        else if (required_unit == 'K')
            return convertCelsiusToKelvin(temperature);

        else if (required_unit == 'R')
            return convertCelsiusToRankine(temperature);
    }

    else if (current_unit == 'F')
    {
        if (required_unit == 'C')
            return convertFahrenheitToCelsius(temperature);

        else if (required_unit == 'K')
            return convertCelsiusToKelvin(convertFahrenheitToCelsius(temperature));

        else if (required_unit == 'R')
            return convertCelsiusToRankine(convertFahrenheitToCelsius(temperature));
    }

    else if (current_unit == 'K')
    {
        if (required_unit == 'C')
            return convertKelvinToCelsius(temperature);

        else if (required_unit == 'F')
            return convertCelsiusToFahrenheit(convertKelvinToCelsius(temperature));

        else if (required_unit == 'R')
            return convertCelsiusToRankine(convertKelvinToCelsius(temperature));
    }

    else
    {
        if (required_unit == 'C')
            return convertRankineToCelsius(temperature);

        else if (required_unit == 'F')
            return convertCelsiusToFahrenheit(convertRankineToCelsius(temperature));

        else
            return convertCelsiusToKelvin(convertRankineToCelsius(temperature));
    }
}

// Main function
int main()
{
    printf("120 degree Celsius to Fahrenheit : %lf\n", unitConverter(120, 'C', 'F'));
    printf("132 Kelvin to Fahrenheit : %lf\n", unitConverter(132, 'K', 'F'));
    printf("190 degree Celsius to Rankine : %lf\n", unitConverter(190, 'C', 'R'));
    printf("243 Kelvin to Rankine : %lf\n", unitConverter(243, 'K', 'R'));
    printf("271 Rankine to Fahrenheit : %lf\n", unitConverter(271, 'R', 'F'));
    printf("291 degree Fahrenheit to Kelvin : %lf\n", unitConverter(291, 'F', 'K'));

    return 0;
}