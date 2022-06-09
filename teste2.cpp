#include <stdio.h>

main()
{
	int op;
	int i, j;
	char Mat[20][14];
	char resp;
	
	//gera a tabela
	for(i = 20; i >= 1; i--)
	for(j = 1; j <= 14; j++)
	Mat[i - 1][j + 1] = '.';
	
	
	do
	{
	
		op = -1;
		while (op != 8)
			{
			printf("\n---------------------------------------------\n");	
			printf("|1 - Check-in de hospede                    |\n");
			printf("|2 - Check-out de hospede                   |\n");
			printf("|3 - Reserva de apartamento                 |\n");
			printf("|4 - Cancelar uma reserva                   |\n");
			printf("|5 - Mapa de ocupacao e reservas do hotel   |\n");
			printf("|6 - Informacoes do hospede                 |\n");
			printf("|7 - Taxas de ocupacao e reservas do hotel  |\n");
			printf("|8 - Sair do programa                       |\n");
			printf("---------------------------------------------\n");
			printf("\nDigite a sua opcao: ");
			scanf("%d", &op);
			switch (op)
				{
			
				case 1: 
					printf("\nVoce ja possui uma reserva? (Responda com s ou n): ");
					scanf("%s", &resp);
					if (i == -1 && j == -1)
						break;
					if(resp == 's' || resp == 'S')
						{
						printf("\nDigite andar e apartamento que esta reservado: ");
						scanf("%d,%d", &i, &j);	
						if (i < 0 || i > 20 || j < 0 || j > 14)
							{
							printf("nao existe esse apartamento\n");
							continue;
							}
						Mat[i - 1][j + 1] = 'O';
						}
					else if	(resp == 'n' || resp == 'N')
							{
								printf("\nDigite andar e apartamento que deseja ocupar: ");
								scanf("%d,%d", &i, &j);	
								
								if (i < 0 || i > 20 || j < 0 || j > 14)
									{
									printf("nao existe esse quarto\n");
									continue;
									}
								if (Mat[i - 1][j + 1] == 'O')	
									{
									printf("\nquarto ocupado\n");	
									continue;
									}
								Mat[i - 1][j + 1] = 'O';	
							}
							
			 	
					break;
				case 2:
					printf("\nDigite andar e apartamento que ira desoculpar: ");
					scanf("%d,%d", &i, &j);	
					if (Mat[i - 1][j + 1] != 'O')	
						{
						printf("\nEste quarto nao estava ocupado\n");	
						continue;
						}
					else
						Mat[i - 1][j + 1] = '.';
					
					break;
				case 3:
					printf("\nDigite andar e apartamento que deseja reservar: ");
					scanf("%d,%d", &i, &j);
						if (i == -1 && j == -1)
						break;
						if (i < 0 || i > 20 || j < 0 || j > 14)
						{
						printf("nao existe esse quarto\n");
							continue;
						}
						if (Mat[i - 1][j + 1] == 'O')	
							{
							printf("\nquarto ocupado\n");	
							continue;
							}
	
					Mat[i - 1][j + 1] = 'R';
					
					break;
				case 4:
					printf("\nDigite andar e apartamento que deseja cancelar a reservar: ");
					scanf("%d,%d", &i, &j);
					if (Mat[i - 1][j + 1] != 'R')	
						{
						printf("\nEste quarto nao esta reservado\n");	
						continue;
						}
					else
						Mat[i - 1][j + 1] = '.';
					
					break;
				case 5:
					//linha superior (numeros das colunas)
					printf("\nApartamentos\t");
					for(j = 1; j <= 14; j++)
						printf("%2d ", j);
					printf("\n\n");
					
					
					//apresentacao da tabela
					for(i = 20; i >= 1; i--)
						{
						printf("Andar %2d\t", i);
						for(j = 1; j <= 14; j++)
							printf(" %c ", Mat[i - 1][j + 1]);
						printf("\n");
						}
					printf("\n\n");
					break;
						
				case 6:
					break;
				case 7:
					float o, r, taxaR, taxaO, taxaT;
					r = 0;
					for(i=20; i>=1; i--)
						for(j= 1 ; j<=14; j++)
						{
							if(Mat[i-1][j+1] == 'R')
								r=r+1;	
						}
					o = 0;
					for(i=20; i>=1; i--)
						for(j= 1 ; j<=14; j++)
						{
							if(Mat[i-1][j+1] == 'O')
								o=o+1;	
						}
					taxaR = r/280 * 100	;
					taxaO = o/280 * 100;
					taxaT = (r+o)/280 * 100;
					printf("\nA taxa de ocupacao e de %5.2f porcento e o de reserva e de %5.2f porcento\n ", taxaO, taxaR);
					printf("o total de ocupado e reservado e de %5.2f porcento\n", taxaT);	
					break;
				
				case 8:
					break; 
						
					
						
					break;
				default:
					printf("opcao invalida\n");
					
				}
			}
		
	}while (op != 8);
	
}
