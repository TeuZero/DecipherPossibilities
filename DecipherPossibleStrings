#include <stdio.h>
#include <string.h>


void generateCombinations(FILE* input, FILE* output) {
    int encryptedValue;
    char decrypted[256];
    int decrypted2[256];
    printf("\n Aguarde o programa esta calculando..., para ver possiveis combinaçoes para decifrar o arquivo...\n");

    while (fscanf(input, "%c", &encryptedValue) > 0) {
        // Reinicializar arrays a cada iteração
        memset(decrypted, 0, sizeof(decrypted));
        memset(decrypted2, 0, sizeof(decrypted2));

        // Percorrer cada caractere da tabela ASCII
        for (int i = 0; i < 256; i++) {
            for (int j = 0; j < 256; j++) {
                for (int k = 0; k < 256; k++) {
                    decrypted[0] = (char)(encryptedValue - i);
                    decrypted2[0] = i + j + k;

                    // Verifica se a condição é verdadeira
                    if (decrypted2[0] == encryptedValue) {
                        printf("Decrypted Text: %c - %c  - %c\n", encryptedValue, decrypted2[0], decrypted[0]);
                        fprintf(output, "%c - %c \n", decrypted2[0], decrypted[0]);
                    }
                }
            }
        }
    }
}


int openFiles(const char* inputFile, const char* outputFile, FILE** input, FILE** output) {
    *input = fopen(inputFile, "rb");
    *output = fopen(outputFile, "wb");

    if (*input == NULL) {
        fprintf(stderr, "Error opening the input file.\n");
        return 0;
    }

    if (*output == NULL) {
        fprintf(stderr, "Error opening the output file.\n");
        fclose(*input);
        return 0;
    }

    return 1;
}



void performOperation(const char* option, const char* inputFile, const char* outputFile) {
    FILE* input;
    FILE* output;

    if (!openFiles(inputFile, outputFile, &input, &output)) {
        return;
    }

    if (strcmp(option, "generateCombinations") == 0)
        generateCombinations(input, output);
      else
        printf("Opção nao reconhecida.\n");

    fclose(input);
    fclose(output);

    printf("Operaçao completa.\n");
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        fprintf(stderr, ": %s <generateCombinations> <input_file> <output_file> \n", argv[0]);
        return 1;
    }
    
    const char* option = argv[1];
    const char* inputFile = argv[2];
    const char* outputFile = argv[3];
    
    performOperation(option, inputFile, outputFile);
    return 0;
}
