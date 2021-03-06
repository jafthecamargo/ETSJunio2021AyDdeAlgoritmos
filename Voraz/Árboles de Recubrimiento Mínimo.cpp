#include"iostream"
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct vertice 
{
    char nod;
    int marca;
    struct vertice *sig;
    struct arco *arc;
};

struct arco 
{
    struct vertice *ver;
    int marca;
    int suma;
    int clave;
    struct arco *sig;
};

struct vertice *pri, *nue, *aux, *ult, *aux2;
struct arco *nueArc, *auxArc, *arcMen, *auxArc2, *antArc;
char auxNod, auxNod2, ban2, let;
int ban, enlace, ban3, ban4, numVer;

void actualizarCampos ();
void crearVertice();
void enlazarVertices();
void enlazar();
void listarAdyacencia();
void obtenerArcoMenor();
void listarAdyacenciaPrim ();
void sumaCaminos();


void crearVertice () 
{
    system ("cls");
    if (pri == NULL)
	{
    	pri = new vertice;
        cout << "El Grafo no tiene Vertices\nDigite la letra del Primer Nodo: ";
        cin >> pri->nod;
        pri->marca = 0;
        pri->arc = NULL;
        pri->sig = NULL;
        ult = pri;
        cout << "\nNodo Registrado";
    } else 
	{
		cout << "Digite la letra del Nodo: ";
        cin >> let;
        do {
        	aux = pri;
            ban = 0;
            while (aux != NULL)
			{
            	if (aux->nod == let)
				{
                	ban = 1;
                }
                aux = aux->sig;
            }
            if (ban == 1) 
			{
            	cout << "\nLetra ya Usada, Igual que las Siguientes:\n";
                aux = pri;
                while (aux != NULL) 
				{
                	cout << aux->nod << " ";
                    aux = aux->sig;
                }
                cout << "\nDigita otra letra: ";
                cin >> let;
        	}
        } while (ban == 1);
        nue = new vertice;
        nue->nod = let;
        nue->marca = 0;
        nue->sig = NULL;
        nue->arc = NULL;
        ult->sig = nue;  
		ult = nue;
        cout << "\nNodo Registrado";   
    }      
    getch();         
}

void enlazarVertices () 
{
    system ("cls");
    if (pri != NULL)
	{
    	aux = pri;
        while (aux != NULL)
		{
        	cout << aux->nod << "\n";
            aux = aux->sig;
        }
        cout << "\nDigite la letra del Nodo a Enlazar: ";
        cin >> auxNod;        
        ban = 0;
        while (ban == 0)
		{
            aux = pri;
            while (aux != NULL && ban == 0)
			{
                if (aux->nod == auxNod)
				{
                    ban = 1;
                }
                aux = aux->sig;
            }
            if (ban == 0)
			{
                cout << "\nEl Nodo no Existe\nDigite uno de los Listados: ";
                cin >> auxNod;
            }
        }
        cout << "\nEstos son los Nodos Disponibles para Enlace:\n";
        aux = pri;
        aux2 = pri;
        while (aux2->nod != auxNod)
		{
            aux2 = aux2->sig;
        }
        while (aux != NULL)
		{
            if (aux->nod != auxNod)
			{
                auxArc = aux2->arc;
                ban4 = 0;
                while (auxArc != NULL && ban4 == 0)
				{	
                    if (aux->nod == auxArc->ver->nod)
					{
                        ban4 = 1;
                    }
                    auxArc = auxArc->sig;
                }
                if (ban4 == 0)
				{
                    cout << aux->nod << "\n";
                }
            }
            aux = aux->sig;
        }
        cout << "\nDigite la Letra del Nodo a Enlazar al Nodo Elegido: ";
        cin >> auxNod2;
        ban = 0;
        while (ban == 0)
		{
            aux = pri; 
            while (auxNod2 == auxNod)
			{
                cout << "\nNo se Puede Hacer el Enlace\nDigite otro Nodo Disponible: ";
                cin >> auxNod2;
            }
            while (aux != NULL && ban == 0)
			{
                if (aux->nod == auxNod2)
				{
                    ban = 1;
                }
                aux = aux->sig;
            }
            if (ban == 0)
			{
                cout << "\nEl Nodo no Existe\nDigite uno de los Listados: ";
                cin >> auxNod2;
            }
        }        
        aux = pri;
        while (aux->nod != auxNod)
		{
            aux = aux->sig;
        }        
        auxArc = aux->arc;
        ban3 = 0;
        while (auxArc != NULL && ban3 == 0)
		{
            if (auxArc->ver->nod == auxNod2)
			{
           		ban3 = 1;
            }
            auxArc = auxArc->sig;
        }
        if (ban3 == 0)
		{
    		enlazar();
            cout << "\nEnlace Creado";
        } else 
		{
            cout << "\nEl Enlace ya Existe\nCompruebe el enlace la Proxima Vez";
        }
    }
}

void enlazar ()
{
    aux = pri;
    while (aux->nod != auxNod)
	{
        aux = aux->sig;
    }
    aux2 = pri;
    while (aux2->nod != auxNod2)
	{
        aux2 = aux2->sig;
    }
    if (aux->arc == NULL)
	{
        nueArc = new arco;
        nueArc->ver = aux2;
        cout << "\nDigite el Peso de la Arista: ";
        cin >> enlace;
        while (nueArc->clave < 0)
		{
            cout << "\nEl Peso debe ser Positivo\nDigite el Peso de la Arista: ";
            cin >> enlace;
        }
        nueArc->clave = enlace;
        nueArc->marca = 0;
        nueArc->suma = 0;
        nueArc->sig = NULL;
        aux->arc = nueArc;
        if (aux2->arc == NULL)
		{
            nueArc = new arco;
            nueArc->ver = aux;           
            nueArc->clave = enlace;
            nueArc->marca = 0;
            nueArc->suma = 0;
            nueArc->sig = NULL;
            aux2->arc = nueArc;
        } else 
		{
            nueArc = new arco;
            nueArc->ver = aux;
            nueArc->clave = enlace;
            nueArc->marca = 0;
            nueArc->suma = 0;
            nueArc->sig = NULL;
            auxArc = aux2->arc;
            while (auxArc->sig != NULL)
			{
                auxArc = auxArc->sig;
            }
            auxArc->sig = nueArc;
        }
	} else 
	{
        nueArc = new arco;
        nueArc->ver = aux2;
        cout << "\nDigite el Peso de la Arista: ";
        cin >> enlace;
        while (enlace < 0)
		{
            cout << "\nEl Peso debe ser Positivo\nDigite el Peso de la Arista: ";
            cin >> enlace;
        }
        nueArc->clave = enlace;  
        nueArc->marca = 0;
        nueArc->suma = 0;         
        nueArc->sig = NULL;
        auxArc = aux->arc;
        while (auxArc->sig != NULL)
		{
            auxArc = auxArc->sig;
        }
        auxArc->sig = nueArc;
        if (aux2->arc == NULL)
		{
            nueArc = new arco;
            nueArc->ver = aux;           
            nueArc->clave = enlace;
            nueArc->marca = 0;
            nueArc->suma = 0;
            nueArc->sig = NULL;
            aux2->arc = nueArc;
        } else 
		{
            nueArc = new arco;
            nueArc->ver = aux;
            nueArc->clave = enlace;
            nueArc->marca = 0;
            nueArc->suma = 0;
            nueArc->sig = NULL;
            auxArc = aux2->arc;
            while (auxArc->sig != NULL)
			{
                auxArc = auxArc->sig;
            }
            auxArc->sig = nueArc;
        }
    }
}

void obtenerArcoMenor () 
{
    aux2 = pri;
    arcMen = NULL;
    while (aux2 != NULL)
	{
        if (aux2->marca == 1)
		{
            auxArc = aux2->arc;
            while (auxArc != NULL)
			{
                if (auxArc->marca == 1)
				{
                    if (arcMen == NULL)
					{
                        arcMen = auxArc;
                    } else
					{
                    	if (auxArc->clave < arcMen->clave)
						{
                        	arcMen = auxArc;
                    	}
                	}
            	}
            	auxArc = auxArc->sig;
        	}
        }
        aux2 = aux2->sig;
    }
    arcMen->marca = 3;
    arcMen->ver->marca = 1;
}

void obtenerSumaMenor () 
{
    aux2 = pri;
    arcMen = NULL;
    while (aux2 != NULL)
	{
        if (aux2->marca == 1)
		{
            auxArc = aux2->arc;
            while (auxArc != NULL)
			{
                if (auxArc->marca == 1)
				{
                    if (arcMen == NULL)
					{
                        arcMen = auxArc;
                    } else
					{
                        if (auxArc->suma < arcMen->suma)
						{
                            arcMen = auxArc;
                        }
                    }
                }
                auxArc = auxArc->sig;
            }
        }
        aux2 = aux2->sig;
    }
    arcMen->marca = 3;
    arcMen->ver->marca = 1;
    auxArc = arcMen->ver->arc;
    while (auxArc != NULL)
	{
        auxArc->suma = arcMen->suma + auxArc->clave;
        auxArc = auxArc->sig;
    }
}

void paso2 ()
{
    obtenerArcoMenor();
    cout << "\nLa Arista Menor es: "<< arcMen->ver->nod << " Peso: " << arcMen->clave;
	getch();
    aux = arcMen->ver;
    auxArc = aux->arc;
    while (auxArc != NULL)
	{
        if (auxArc->ver->marca == 0)
		{
            aux2 = pri;
            while (aux2 != NULL)
			{
                if (aux2 != aux && aux2->marca == 1)
				{
                    auxArc2 = aux2->arc;
                    while (auxArc2 != NULL)
					{
                        if (auxArc->ver->nod == auxArc2->ver->nod)
						{
                            if (auxArc->clave < auxArc2->clave)
							{
                                auxArc2->marca = 2;
                                auxArc->marca = 1;
                            } else 
							{
                                auxArc->marca = 2;
                                auxArc2->marca = 1;
                            }
                        }
                        auxArc2 = auxArc2->sig;
                    }
                }
                aux2 = aux2->sig;
            }
            if (auxArc->marca == 0)
			{
                auxArc->marca = 1;
            }
        } else 
		{
            auxArc->marca = 2;
        }
        auxArc = auxArc->sig;
    }
}

void algoritmoPrim () 
{
    system("cls");
    if (pri != NULL)
	{
        actualizarCampos();
        cout << "Digite el Nodo Inicial: ";
        cin >> auxNod;
        ban = 0;
        while (ban == 0)
		{
            aux = pri;
            while (aux != NULL)
			{
                if (aux->nod == auxNod)
				{
                    ban = 1;
                }
                aux = aux->sig;
            }
            if (ban == 0)
			{
                cout << "\nNo Existe un Nodo con esa Letra.";
                aux = pri;
                cout << "\n---Lista de Nodos---\n";
                while (aux != NULL)
				{
                    cout << aux->nod << " ";
                    aux = aux->sig;
                }
                cout << "\nDigite uno de los Nodos: ";
                cin >> auxNod;
            }
        }
        aux = pri;
        while (aux->nod != auxNod)
		{
            aux = aux->sig;
    	}
        aux->marca = 1;
        auxArc = aux->arc;
        while (auxArc != NULL)
		{
            auxArc->marca = 1;
            auxArc = auxArc->sig;
        }
        cout << "\nSe han Marcado todos las Aristas para el Nodo Elegido";
        ban2 = 1;
        while (ban2 == 1)
		{
            paso2();
            ban2 = 0;
            aux = pri;
            while (aux != NULL)
			{
                if (aux->marca == 0)
				{
                    ban2 = 1;
                }
                aux = aux->sig;
            }
        }
        listarAdyacenciaPrim ();
        sumaCaminos();
    }
    getch();
}

void listarAdyacencia () 
{
    system ("cls");
    if (pri != NULL)
	{
        aux = pri;
        cout << "---Lista de Adyacencia---\n";
        while (aux != NULL)
		{
            auxArc = aux->arc;
            cout << "\n|\n" << aux->nod << "->";
            while (auxArc != NULL)
			{
                cout << auxArc->ver->nod << " ";
                auxArc = auxArc->sig;
            }
            aux = aux->sig;
        }
        getch();
    }
}

void sumaCaminos () 
{
    aux = pri;
    int suma = 0;
    while (aux != NULL)
	{
        auxArc = aux->arc;
    	while (auxArc != NULL)
		{
            if (auxArc->marca == 3)
			{
                suma = suma + auxArc->clave;
            }
            auxArc = auxArc->sig;
        }
        aux = aux->sig;
    }
    cout << "\nLa Suma de los Pesos es: " << suma;
}

void listarAdyacenciaPrim () 
{
    if (pri != NULL)
	{
        aux = pri;
        cout << "\n---Lista de Adyacencia---\n";
        while (aux != NULL)
		{
            auxArc = aux->arc;
            cout << "\n|\n" << aux->nod << "->";
            while (auxArc != NULL)
			{
                if (auxArc->marca == 3)
                cout << auxArc->ver->nod << " ";
                auxArc = auxArc->sig;
            }
            aux = aux->sig;
        }
    }
}

void actualizarCampos () 
{
    aux = pri;
    while (aux != NULL)
	{
        auxArc = aux->arc;
        while (auxArc != NULL)
		{
            auxArc->marca = 0;
            auxArc->suma = 0;
            auxArc = auxArc->sig;
        }
    	aux->marca = 0;
        aux = aux->sig;
    }
}

main (){
    int op = 0;
    do {
		system("cls");
 	    cout<<"-----MENU-----";
        cout<<"\n1.- Crear Nodo";
        cout<<"\n2.- Enlazar Nodos";
        cout<<"\n3.- Listar Nodos con su Adyacencia";
        cout<<"\n4.- Algoritmo de Prim";
        cout<<"\n5.- Salir";
        cout<<"\n\nOpcion: ";
        cin>>op;
        while (op>5)
	    {
        	cout << "Esa Opcion no Existe, Digite un Numero del 1 al 5: ";
            cin >> op;
        }
        switch(op)
		{
        	case 1: 
			crearVertice(); 
			break;
            case 2: 
			enlazarVertices(); 
			getch(); 
			break;
            case 3: 
			listarAdyacencia(); 
			break;
            case 4: 
			algoritmoPrim(); 
			break;
            case 5: 
			exit(0);
        }
	} while(op<6);
}
