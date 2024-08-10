#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição de uma estrutura de dados para um Personagem
typedef struct _personagem {
    char nome[20];
    char nomeAtor[20];
    int idade;
} Personagem;

// Definição de uma estrutura de dados para uma Serie
typedef struct _serie {
    char titulo[20];
    char genero[15];
    int ano;
    int numPersonagens;
    Personagem *personagens[10];
} Serie;

// Função para cadastrar um novo personagem
Personagem *cadastrarPersonagem() {
    Personagem *novoPersonagem = (Personagem *)malloc(sizeof(Personagem));
    if (novoPersonagem == NULL) {
        printf("Erro ao alocar memoria para o personagem.\n");
        return NULL;
    }

    printf("Digite o nome do personagem: ");
    scanf(" %[^\n]", novoPersonagem->nome);
    printf("Digite nome do Ator: ");
    scanf(" %[^\n]", novoPersonagem->nomeAtor);
    printf("Digite a idade do Ator: ");
    scanf("%d", &novoPersonagem->idade);
    return novoPersonagem;
}

// Função para cadastrar uma nova serie
Serie *cadastrarSerie() {
    Serie *novaSerie = (Serie *)malloc(sizeof(Serie));
    if (novaSerie == NULL) {
        printf("Erro ao alocar memoria para a serie.\n");
        return NULL;
    }

    printf("Digite o nome da serie: ");
    scanf(" %[^\n]", novaSerie->titulo);
    printf("Digite o genero da serie: ");
    scanf(" %[^\n]", novaSerie->genero);
    printf("Digite o ano de lançamento da serie: ");
    scanf("%d", &novaSerie->ano);
    novaSerie->numPersonagens = 0;
    return novaSerie;
}

// Função para listar informações de todas as series
void listarSeries(Serie *series[], int numSeries) {
    int i, j;
    for (i = 0; i < numSeries; i++) {
        printf("Serie: %s\n", series[i]->titulo);
        printf("Genero: %s\n", series[i]->genero);
        printf("Ano de lançamento: %d\n", series[i]->ano);
        printf("Numero de personagens: %d\n", series[i]->numPersonagens);
        printf("Personagens:\n");
        for (j = 0; j < series[i]->numPersonagens; j++) {
            printf("\tNome do personagem: %s\n", series[i]->personagens[j]->nome);
            printf("\tNome do Ator: %s\n", series[i]->personagens[j]->nomeAtor);
            printf("\tIdade do Ator: %d\n", series[i]->personagens[j]->idade);
        }
    }
}

// Função para listar informações de todos os personagens
void listarPersonagens(Personagem *personagens[], int numPersonagens) {
    int i;
    for (i = 0; i < numPersonagens; i++) {
        printf("Nome: %s\n", personagens[i]->nome);
        printf("Nome do Ator: %s\n", personagens[i]->nomeAtor);
        printf("Idade do Ator: %d\n", personagens[i]->idade);
    }
}

// Função para editar informações de um personagem
void editarPersonagem(Personagem *personagens[], int numPersonagens) {
    if (numPersonagens == 0) {
        printf("Nao existem personagens cadastrados.\n");
        printf("Nao eh possivel realizar a operacao!\n");
        return;
    }

    char nomePersonagem[40];
    int i, opcao;

    printf("Digite o personagem que deseja editar: ");
    scanf(" %[^\n]s", nomePersonagem);

    for (i = 0; i < numPersonagens; i++) {
        if (strcmp(nomePersonagem, personagens[i]->nome) == 0) {
            printf("Digite:\n");
            printf("  1 para editar o nome\n");
            printf("  2 para editar o nome do ator\n");
            printf("  3 para editar a idade\n");
            scanf(" %d", &opcao);
            switch (opcao) {
                case 1:
                    printf("Digite o novo nome do personagem: ");
                    scanf(" %[^\n]s", personagens[i]->nome);
                    break;
                case 2:
                    printf("Digite o novo nome do ator: ");
                    scanf(" %[^\n]s", personagens[i]->nomeAtor);
                    break;
                case 3:
                    printf("Digite a nova idade: ");
                    scanf("%d", &personagens[i]->idade);
                    break;
                default:
                    printf("Opcao invalida!\n\n");
                    return;
            }
            printf("Operacao realizada com sucesso!\n\n");
            break;
        }
    }
}

// Função para editar informações de uma série
void editarSerie(Serie *series[], int numSeries) {
    if (numSeries == 0) {
        printf("Nao existem series cadastrados!\n");
        printf("Nao eh possivel realizar a operacao!\n");
        return;
    }

    char nomeSerie[40];
    int i, opcao;

    printf("Digite o nome da serie que deseja editar: ");
    scanf(" %[^\n]s", nomeSerie);

    for (i = 0; i < numSeries; i++) {
        if (strcmp(nomeSerie, series[i]->titulo) == 0) {
            printf("Digite:\n");
            printf(" 1 para editar o titulo\n");
            printf(" 2 para editar o genero\n");
            printf(" 3 para editar o ano de lancamento\n");
            scanf(" %d", &opcao);
            switch (opcao) {
                case 1:
                    printf("Digite o novo titulo\n");
                    scanf(" %[^\n]s", series[i]->titulo);
                    break;
                case 2:
                    printf("Digite o novo genero\n");
                    scanf(" %[^\n]s", series[i]->genero);
                    break;
                case 3:
                    printf("Digite o novo ano de lancamento\n");
                    scanf("%d", &series[i]->ano);
                    break;
                default:
                    printf("Opcao invalida!\n\n");
                    return;
            }
            printf("Operacao realizada com sucesso!\n\n");
            break;
        }
    }
}

// Função para remover um personagem
void removerPersonagem(Personagem *personagens[], int *numPersonagens) {
    if (*numPersonagens == 0) {
        printf("Nao existem personagens cadastrados.\n");
        printf("Nao eh possivel realizar a operacao!\n");
        return;
    }

    char nomePersonagem[40];
    int i, encontrei = 0;

    printf("Digite o nome do personagem para remover: ");
    scanf(" %[^\n]", nomePersonagem);

    for (i = 0; i < *numPersonagens; i++) {
        if (strcmp(nomePersonagem, personagens[i]->nome) == 0) {
            encontrei = 1;
            free(personagens[i]); // Libere a memória do personagem removido
        }

        if (encontrei) {
            if (i < *numPersonagens - 1) {
                personagens[i] = personagens[i + 1];
            }
        }
    }

    if (encontrei) {
        (*numPersonagens)--;
        printf("Operacao realizada com sucesso!\n\n");
    } else {
        printf("Personagem nao encontrado!\n\n");
    }
}

// Função para remover uma série
void removerSerie(Serie *series[], int *numSeries) {
    char tituloSerie[40];
    int i, encontrei = 0;

    printf("Digite o titulo da serie para remover: ");
    scanf(" %[^\n]", tituloSerie);

    for (i = 0; i < *numSeries; i++) {
        if (strcmp(tituloSerie, series[i]->titulo) == 0) {
            encontrei = 1;
            // Libere a memória dos personagens da série removida
            for (int j = 0; j < series[i]->numPersonagens; j++) {
                free(series[i]->personagens[j]);
            }
            free(series[i]); // Libere a memória da série removida
        }

        if (encontrei) {
            if (i < *numSeries - 1) {
                series[i] = series[i + 1];
            }
        }
    }
    if (encontrei) {
        (*numSeries)--;
        printf("Operacao realizada com sucesso!\n\n");
    } else {
        printf("Serie nao encontrada!\n\n");
    }
}

// Função para adicionar um personagem a uma série
void adicionarPersonagemNaSerie(Serie *serie, Personagem *personagem) {
    if (serie->numPersonagens < 10) {
        serie->personagens[serie->numPersonagens] = personagem;
        serie->numPersonagens++;
    } else {
        printf("Limite de personagens na serie atingido!\n");
    }
}

int main() {
    Personagem *personagens[100];
    Serie *series[100];
    int numPersonagens = 0;
    int numSeries = 0;
    char opcao;

    do {
        printf("\nEscolha uma opcao:\n");
        printf("1. Cadastrar personagem\n");
        printf("2. Cadastrar serie\n");
        printf("3. Listar personagens\n");
        printf("4. Listar series\n");
        printf("5. Editar personagem\n");
        printf("6. Editar serie\n");
        printf("7. Remover personagem\n");
        printf("8. Remover serie\n");
        printf("9. Adicionar personagem a serie\n");
        printf("0. Sair\n");
        printf("Opcao: ");
        scanf(" %c", &opcao);

        switch (opcao) {
            case '1':
                if (numPersonagens < 100) {
                    personagens[numPersonagens] = cadastrarPersonagem();
                    if (personagens[numPersonagens] != NULL) {
                        numPersonagens++;
                        printf("Personagem cadastrado com sucesso!\n");
                    } else {
                        printf("Erro ao alocar memória para o personagem.\n");
                    }
                } else {
                    printf("Limite de personagens atingido!\n");
                }
                break;
            case '2':
                if (numSeries < 100) {
                    series[numSeries] = cadastrarSerie();
                    if (series[numSeries] != NULL) {
                        numSeries++;
                        printf("Serie cadastrada com sucesso!\n");
                    } else {
                        printf("Erro ao alocar memoria para a serie.\n");
                    }
                } else {
                    printf("Limite de series atingido!\n");
                }
                break;
            case '3':
                if (numPersonagens > 0){
                    listarPersonagens(personagens, numPersonagens);
                } else {
                    printf("Nenhum personagem cadastrado!\n");
                }
                break;
            case '4':
                if(numSeries > 0 ){
                    listarSeries(series, numSeries);
                } else {
                    printf("Nenhuma serie cadastrada!\n");
                }
                break;
            case '5':
                if(numPersonagens > 0){
                    editarPersonagem(personagens, numPersonagens);
                }else {
                    printf("Nenhum personagem encontrado\n");
                }
                break;
            case '6':
                editarSerie(series, numSeries);
                break;
            case '7':
                removerPersonagem(personagens, &numPersonagens);
                numPersonagens--;
                break;
            case '8':
                removerSerie(series, &numSeries);
                numSeries--;
                break;
            case '9':
                if (numSeries > 0 && numPersonagens > 0) {
                    char nomeSerie[40];
                    char nomePersonagem[40];
                    int serieEncontrada = 0;
                    int personagemEncontrado = 0;

                    printf("Digite o nome da serie a qual deseja adicionar o personagem: ");
                    scanf(" %[^\n]", nomeSerie);

                    for (int i = 0; i < numSeries; i++) {
                        if (strcmp(nomeSerie, series[i]->titulo) == 0) {
                            serieEncontrada = 1;

                            printf("Digite o nome do personagem que deseja adicionar a esta serie: ");
                            scanf(" %[^\n]", nomePersonagem);

                            for (int j = 0; j < numPersonagens; j++) {
                                if (strcmp(nomePersonagem, personagens[j]->nome) == 0) {
                                    personagemEncontrado = 1;
                                    adicionarPersonagemNaSerie(series[i], personagens[j]);
                                    printf("Personagem adicionado a serie com sucesso!\n");
                                    break;
                                }
                            }

                            if (!personagemEncontrado) {
                                printf("Personagem nao encontrado!\n");
                            }
                            break;
                        }
                    }

                    if (!serieEncontrada) {
                        printf("Serie nao encontrada!\n");
                    }
                } else {
                    printf("Series ou personagens nao cadastrados para adicionar\n");
                }
                break;
            case '0':
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != '0');

    // Liberação de memória alocada para personagens e séries
    for (int i = 0; i < numPersonagens; i++) {
        free(personagens[i]);
    }

    for (int i = 0; i < numSeries; i++) {
        for (int j = 0; j < series[i]->numPersonagens; j++) {
            free(series[i]->personagens[j]);
        }
        free(series[i]);
    }

    return 0;
}

