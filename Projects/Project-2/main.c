#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* MENU LIST */
#define     LENGTH_MENU         1
#define     WEIGHT_MENU         2
#define     TEMP_MENU           3
#define     EXIT_COMMAND        4
#define     MAX_COMMAND_COUNT   5

/* LENGTH CONVERTER COMMANDS */
#define     METER_TO_INCH    1
#define     INCH_TO_METER    2
#define     KM_TO_MILE       3
#define     MILE_TO_KM       4

/* WEIGHT CONVERTER COMMANDS */
#define     KG_TO_POUND     1
#define     POUND_TO_KG     2
#define     GR_TO_OUNCE     3
#define     OUNCE_TO_GR     4   

/* TEMPERATURE CONVERTER COMMANDS */
#define     C_TO_F          1
#define     F_TO_C          2
#define     C_TO_K          3
#define     K_TO_C          4

/* LENGTH FUNCTIONS */
double meterToInch(double m) { return m * 39.3701; }
double inchToMeter(double inch) { return inch / 39.3701; }
double kmToMile(double km) { return km * 0.621371; }
double mileToKm(double mil) { return mil / 0.621371; }

/* WEIGHT FUNCTIONS */
double kgToPound(double kg) { return kg * 2.20462; }
double poundToKg(double lb) { return lb /2.20462; }
double gToOunce(double g) { return g * 0.035274; }
double ounceToG(double oz) { return oz / 0.035274; }

/* TEMPERATURE FUNCTIONS */
double cToF(double c) { return (c * 9.0/5.0) + 32.0; }
double fToC(double f) { return (f - 32.0) * 5.0/9.0; }
double cToK(double c) { return (c + 273.15); }
double kToC(double k) { return k - 273.15; }

void showMainMenu()
{
    printf("=== Unit Converter ===\n");
    printf("1. Length\n");
    printf("2. Weight\n");
    printf("3. Temperature\n");
    printf("4. Exit\n");
    // printf("Your choice: ");
}

void printHelp()
{
    printf("Usage:\n");
    printf("unit-converter.exe --type=TYPE --from=UNIT1 --to=UNIT2 --value=NUM\n");
    printf("ex: unit-converter.exe --type=weight --from=kg --to=pound --value=5\n");
    printf("Supported types: length, weight, temperature\n");
    printf("Supported units: meter, inch, km, mile | kg, lb, gr, ons | C, K, F\n");
}

void lengthMenu()
{
    int choice;
    double val;

    printf("Uzunluk Donusturme\n");
    printf("1. Metre     -> Inc\n");
    printf("2. Inc       -> Metre\n");
    printf("3. Kilometre -> Mil\n");
    printf("4. Mil       -> Kilometre\n");
    // printf("Your choice: ");
    // scanf("%d", &choice);
    // printf("Enter value: ");
    // scanf("%lf", &val);

    // switch (choice)
    // {
    //     case METER_TO_INCH:
    //         printf("Result: %.2lf inch\n", meterToInch(val));
    //         break;
        
    //     case INCH_TO_METER:
    //         printf("Result: %.2lf m\n", inchToMeter(val));
    //         break;
        
    //     case KM_TO_MILE:
    //         printf("Result: %.2lf mil\n", kmToMile(val));
    //         break;
        
    //     case MILE_TO_KM:
    //         printf("Result: %.2lf km\n", mileToKm(val));
    //         break;

    //     default:
    //         printf("Unvalid Choice!\n");
    //         break;
    // }
}

void weightMenu()
{
    int choice;
    double val;

    printf("Weight Converter\n");
    printf("1. Kilogram  -> Pound\n");
    printf("2. Pound     -> Kilogram\n");
    printf("3. Gram      -> Ounce\n");
    printf("4. Ounce     -> Gram\n");
    // printf("Your choice: ");
    // scanf("%d", &choice);
    // printf("Deger girin: ");
    // scanf("%lf", &val);

    // switch (choice)
    // {
    //     case KG_TO_POUND:
    //         printf("Result: %.2lf lb\n", kgToPound(val));
    //         break;
        
    //     case POUND_TO_KG:
    //         printf("Result: %.2lf kg\n", poundToKg(val));
    //         break;
        
    //     case GR_TO_OUNCE:
    //         printf("Result: %.2lf oz\n", gToOunce(val));
    //         break;
        
    //     case OUNCE_TO_GR:
    //         printf("Result: %.2lf g\n", ounceToG(val));
    //         break;

    //     default:
    //         printf("Unvalid Choice!\n");
    //         break;
    // }
}

void temperatureMenu()
{
    int choice;
    double val;

    printf("Temperature Converter\n");
    printf("1. Celsius      -> Fahrenheit\n");
    printf("2. Fahrenheit   -> Celsius\n");
    printf("3. Celsius      -> Kelvin\n");
    printf("4. Kelvin       -> Celsius\n");
    // printf("Your choice: ");
    // scanf("%d", &choice);
    // printf("Deger girin: ");
    // scanf("%lf", &val);

    // switch (choice)
    // {
    //     case C_TO_F:
    //         printf("Result: %.2lf F\n", cToF(val));
    //         break;
        
    //     case F_TO_C:
    //         printf("Result: %.2lf C\n", fToC(val));
    //         break;
        
    //     case C_TO_K:
    //         printf("Result: %.2lf K\n", cToK(val));
    //         break;
        
    //     case K_TO_C:
    //         printf("Result: %.2lf C\n", kToC(val));
    //         break;

    //     default:
    //         printf("Unvalid Choice!\n");
    //         break;
    // }
}

int main(int argc, char *argv[])
{   
    if(strncmp(argv[1], "--help", 8) == 0)
    {
        lengthMenu();
        printf("==================\n");
        weightMenu();
        printf("==================\n");
        temperatureMenu();
        return 1;
    }

    else if(strncmp(argv[1], "--usage", 9) == 0)
    {
        printHelp();
        return 1;
    }

    if(argc != MAX_COMMAND_COUNT)
    {
        printHelp();
        return 1;
    }

    char type[20] = "", from[20] = "", to[20] = "";
    double value = 0;

    for (int i = 1; i < argc; i++)
    {
        if(strncmp(argv[i], "--type=", 7) == 0)
            strcpy(type, argv[i] + 7);
        else if (strncmp(argv[i], "--from=", 7) == 0)
            strcpy(from, argv[i] + 7);
        else if (strncmp(argv[i], "--to=", 5) == 0)
            strcpy(to, argv[i] + 5);
        else if (strncmp(argv[i], "--value=", 8) == 0)
            value = atof(argv[i] + 8);
        else 
        {
            printf("Unknown argument: %s\n", argv[i]);
            return 1;
        }
    }

    double result = 0;
    if(strcmp(from, "meter") == 0 && strcmp(to, "inch") == 0)
        result = meterToInch(value);
    else if(strcmp(from, "inch") == 0 && strcmp(to, "meter") == 0)
        result = inchToMeter(value);
    else if(strcmp(from, "km") == 0 && strcmp(to, "mile") == 0)
        result = kmToMile(value);
    else if(strcmp(from, "mile") == 0 && strcmp(to, "km") == 0)
        result = mileToKm(value);
    else {
        printf("Unknown converter: %s --> %s\n", from, to);
        return 1;
    }

    printf("Sonuc: %.4lf %s\n", result, to);
}