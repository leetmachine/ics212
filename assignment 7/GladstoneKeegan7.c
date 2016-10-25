/*
Display the Japanese word for numbers 1-9999.
Gladstone, Keegan
Assignment 7
01/31/2016
*/

#include <stdio.h>


int main() {
    
    int x = 0;
    int ones = 0;
    int tens = 0;
    int hundreds = 0;
    int thousands = 0;
    
    char *onesWord = "";
    char *tensWord = "";
    char *hundredsWord = "";
    char *thousandsWord = "";
    
    puts("This program will count in Japanese word from 1-9999.");
    
    for(x = 1; x < 10000; x++) {
        
        ones = (x%10);
        tens = (x/10)%10;
        hundreds = (x/100)%10;
        thousands = (x/1000)%10;
        
        switch(thousands) {
            case 0:
                thousandsWord = "";
                break;
            case 1:
                thousandsWord = "sen";
                break;
            case 2:
                thousandsWord = "nisen";
                break;
            case 3:
                thousandsWord = "sanzen";
                break;
            case 4:
                thousandsWord = "yonsen";
                break;
            case 5:
                thousandsWord = "gosen";
                break;
            case 6:
                thousandsWord = "rokusen";
                break;
            case 7:
                thousandsWord = "nanasen";
                break;
            case 8:
                thousandsWord = "hassen";
                break;
            case 9:
                thousandsWord = "kyuusen";
                break;
        }
        
        
        switch(hundreds) {
            case 0:
                hundredsWord = "";
                break;
            case 1:
                hundredsWord = "hyaku";
                break;
            case 2:
                hundredsWord = "nihyaku";
                break;
            case 3:
                hundredsWord = "sanhyaku";
                break;
            case 4:
                hundredsWord = "yonhyaku";
                break;
            case 5:
                hundredsWord = "gohyaku";
                break;
            case 6:
                hundredsWord = "rokuhyaku";
                break;
            case 7:
                hundredsWord = "nanahyaku";
                break;
            case 8:
                hundredsWord = "happhyaku";
                break;
            case 9:
                hundredsWord = "kyuuhyaku";
                break;
        }
        
        
        
        
        
        switch(tens) {
            case 0:
                tensWord = "";
                break;
            case 1:
                tensWord = "kyuu";
                break;
            case 2:
                tensWord = "nijyuu";
                break;
            case 3:
                tensWord = "sanjyuu";
                break;
            case 4:
                tensWord = "yonjyuu";
                break;
            case 5:
                tensWord = "gojyuu";
                break;
            case 6:
                tensWord = "rokujyuu";
                break;
            case 7:
                tensWord = "nanajyuu";
                break;
            case 8:
                tensWord = "hachijyuu";
                break;
            case 9:
                tensWord = "kyuujyuu";
                break;
                
        }
        
        switch(ones) {
            case 0:
                onesWord = "";
                break;
            case 1:
                onesWord = "ichi";
                break;
            case 2:
                onesWord = "ni";
                break;
            case 3:
                onesWord = "san";
                break;
            case 4:
                onesWord = "yon";
                break;
            case 5:
                onesWord = "go";
                break;
            case 6:
                onesWord = "roku";
                break;
            case 7:
                onesWord = "nana";
                break;
            case 8:
                onesWord = "hachi";
                break;
            case 9:
                onesWord = "kyuu";
                break;
        }
        
        
        
        
        
        
        
        
        printf("%i = %s %s %s %s\n", x, thousandsWord, hundredsWord, tensWord, onesWord);
    }
    
    
    
    
    
    
    
    
    return 0;
}