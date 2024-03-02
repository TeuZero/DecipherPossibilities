#include <stdio.h>
#include <string.h>

void generateCNumbers(FILE* input, FILE* output, int maxDigits) {
    char characters[256];
    char currentCombination[256];

    // Ler os caracteres do arquivo de entrada
    int characterCount = 0;
    while (fscanf(input, " %c", &characters[characterCount]) == 1) {
        characterCount++;
    }

    // Função recursiva para gerar combinações
    void generate(int position, int digits) {
        if (digits > maxDigits) {
            // Chegamos ao número máximo de dígitos, pular para uma nova linha
            fprintf(output, "\n");
            return;
        }

        if (position == characterCount) {
            // Chegamos ao final da combinação, gravar no arquivo
            fprintf(output, "%s ", currentCombination);
            generate(0, digits + 1);  // Reiniciar a partir da posição 0 com mais um dígito
            return;
        }

        // Para cada caractere, incluir na combinação e chamar a função recursivamente
        for (int i = 0; i < characterCount; i++) {
            currentCombination[position] = characters[i];
            generate(position + 1, digits);
        }
    }

    // Iniciar a geração a partir da posição 0 e com 1 dígito
    generate(0, 1);
}



void generates(FILE* input, FILE* output) {
    char characters[256];
    char currentCombination[256];
	
	printf("Aguarde o programa esta gerando as combinacoes isso ira levar tempo...\n");
    // Ler os caracteres do arquivo de entrada
    int characterCount = 0;
    while (fscanf(input, " %c", &characters[characterCount]) == 1) {
        characterCount++;
    }

    // Função recursiva para gerar combinações
    void generate(int position) {
        if (position == characterCount) {
            // Chegamos ao final da combinação, gravar no arquivo
            fprintf(output, "%s\n", currentCombination);
            return;
        }

        // Para cada caractere, incluir na combinação e chamar a função recursivamente
        for (int i = 0; i < characterCount; i++) {
            currentCombination[position] = characters[i];
            generate(position + 1);
        }
    }

    // Iniciar a geração a partir da posição 0
    generate(0);
    printf("Geracoes concluidas com sucesso!\n");
}


void generateCombinations(FILE* input, FILE* output) {
    int encryptedValue;
    char decrypted[256];
    int decrypted2[256];
    printf("\n Aguarde o programa esta calculando..., para ver possiveis combinacoes para decifrar o arquivo...\n");

    while (fscanf(input, "%c", &encryptedValue) > 0) {
        // Reinicializar arrays a cada iteração
        memset(decrypted, 0, sizeof(decrypted));
        memset(decrypted2, 0, sizeof(decrypted2));

        // Percorrer cada caractere da tabela ASCII
        for (int i = 0; i < 256; i++) {
            for (int j = 0; j < 256; j++) {
                for (int k = 0; k < 256; k++) {
                    decrypted[0] = (char)(encryptedValue + i) ;
                    decrypted2[0] = i + j + k;

                    // Verifica se a condição é verdadeira
                    if (decrypted2[0] == encryptedValue) {
                        printf("Decrypted char: %c - %c  - %c\n", encryptedValue, decrypted2[0], decrypted[0]);
                        fprintf(output, "%c %c \n", decrypted2[0], decrypted[0]);
                    }
                    decrypted[0] = (char)(encryptedValue -(char)"") - 15;
                    
					if (decrypted2[0] == encryptedValue) {
                        printf("Decrypted char: %c - %c  - %c\n", encryptedValue, decrypted2[0], decrypted[0]);
                        fprintf(output, "%c %c \n", decrypted2[0], decrypted[0]);
                    }
                         
                      decrypted[0] = (char)(encryptedValue + i) + (25 + 29 );     
                    if (decrypted2[0] == encryptedValue) {
                        printf("Decrypted char: %c - %c  - %c\n", encryptedValue, decrypted2[0], decrypted[0]);
                        fprintf(output, "%c %c \n", decrypted2[0], decrypted[0]);
                    }
                    
                    decrypted[0] = (char)(encryptedValue ^ i);     
                    if (decrypted2[0] == encryptedValue) {
                        printf("Decrypted char: %c - %c  - %c\n", encryptedValue, decrypted2[0], decrypted[0]);
                        fprintf(output, "%c %c \n", decrypted2[0], decrypted[0]);
                    }
                }
            }
        }
    }
}

// Função para verificar se uma combinação já existe no buffer
int isDuplicate(const char* buffer, const char* combination) {
    const char* ptr = buffer;

    while (*ptr != '\0') {
        if (strstr(ptr, combination) != NULL) {
            return 1;  // Duplicado encontrado
        }
        // Avança para o próximo conjunto de caracteres
        ptr += strlen(ptr) + 1;
    }

    return 0;  // Nenhum duplicado encontrado
}

void removeDuplicates(FILE* input, FILE* output) {
    char buffer[256][50];  // Buffer para armazenar as combinações únicas
    int bufferIndex = 0;

    printf("Removendo duplicatas...\n");

    while (fscanf(input, "%s", buffer[bufferIndex]) > 0) {
        // Verifica se a combinação já existe no buffer
        int duplicate = 0;
        for (int i = 0; i < bufferIndex; i++) {
            if (strcmp(buffer[i], buffer[bufferIndex]) == 0) {
                duplicate = 1;
                break;
            }
        }

        if (!duplicate) {
            // Adiciona a combinação ao buffer
            fprintf(output, "%s\n", buffer[bufferIndex]);
            bufferIndex++;
        }
    }

    printf("Duplicatas removidas.\n");
}

// Essa função combinations está em teste
void combinations(FILE* input, FILE* output) {
    int decryptedValue;
    char combination[256];
    int decrypted2[256];
    int decrypted3[256];
    char combinedResults[256] = "";
   	int init;

    printf("Aguarde enquanto o programa esta combinando os resultados.\n");
    printf("Isso pode levar um tempo...\n");
		
    while (fscanf(input, "%c", &decryptedValue) > 0) {
		 
        for (int i = 0; i < 256; i++) {
            for (int j = 0; j < 256; j++) {
                for (int k = 0; k < 256; k++) {
                    combination[0] = (char)(decryptedValue - i);
                    decrypted2[0] = i + j + k;                
                    char tempBuffer[50];
                    sprintf(tempBuffer, "%c-%c%c", decryptedValue,combination[0] ,decrypted2[0] );
						
			        //printf("%s\n", tempBuffer);
			        fprintf(output, "%s\n", tempBuffer);    
					printf("Decrypted Text: %c- %c%c\n", decryptedValue,combination[0] ,decrypted2[0]);	

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

int performOperation(const char* option, const char* inputFile, const char* outputFile) {
    FILE* input;
    FILE* output;

    if (!openFiles(inputFile, outputFile, &input, &output)) {
        fclose(input);
    	fclose(output);
		return 1;
    }

	if (strcmp(option, "generateCombinations") == 0) {
	    generateCombinations(input, output);
	} else if (strcmp(option, "combinations") == 0) {
	    combinations(input, output);
	} else if (strcmp(option, "removeDuplicates") == 0) {
	    removeDuplicates(input, output);
	} else if(strcmp(option, "generates") == 0){
		generates(input, output);
	}else if(strcmp(option, "generateCNumbers") == 0){
		generateCNumbers(input, output, maxDigits);
		printf("Exemplo: %c generateCNumbers <input_file> <output_file> <maximoDeDigitos> ", argv[0])
		
	}else{
	    printf("Opcao nao reconhecida.\n");
	    fclose(input);
	    fclose(output);
	    return 1;
	}
    fclose(input);
    fclose(output);

    printf("Operacao completa.\n");
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        fprintf(stderr, ": %s <generateCombinations/removeDuplicates/combinations/generates/generateCNumbers> <input_file> <output_file> \n", argv[0]);
        return 1;
    }
    
    const char* option = argv[1];
    const char* inputFile = argv[2];
    const char* outputFile = argv[3];
    
    performOperation(option, inputFile, outputFile);
    return 0;
}
