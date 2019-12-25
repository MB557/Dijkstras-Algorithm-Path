#include<stdio.h>
#include<stdlib.h>

struct node
{
    int value, weight;
    struct node *link;
};

void Input(struct node *Head[],struct node *Root[],int u,int v, int w)
{
    struct node *Temp2=(struct node*)malloc(sizeof(struct node));
    Temp2->value=v;
    Temp2->weight=w;
    Temp2->link=NULL;

    if(Head[u]==NULL)
    {
        Head[u]=Temp2;
        Root[u]=Temp2;
    }
    else
    {
        Root[u]->link=Temp2;
        Root[u]=Temp2;
    }
}

int getMinValue(int Cost[], int Traverse[], int V)
{
    int var,min=10000;

    for (int i = 0; i < V; ++i)
    {
		if (min > Cost[i] && Traverse[i] == 0)
        {
			min = Cost[i];
			var=i;
		}
	}
	return var;
}

void dijkstra_logic(struct node * Head[], struct node * Root[], int V, int Cost[], int Traverse[], int Parent[])
{
    int min,c,Min_Value;

    for (int i = 0; i < V; ++i)
    {
        Cost[i] = 9999;
        Traverse[i] = 0;
        Parent[i]=-1;
    }

    Traverse[0]=1;
    Cost[0] = 0;
    Min_Value=0;
    Parent[0]=0;
    while (1)
    {
        c =0;
        for(int i=0;i<V;++i)
            if(Traverse[i] == 1)
                c++;
        if(c == V)
            break;

		Root[Min_Value] = Head[Min_Value];
		while (Root[Min_Value] != NULL)
        {
            if (Traverse[Root[Min_Value]->value]==0 && Cost[Root[Min_Value]->value] > Cost[Min_Value] + Root[Min_Value]->weight)
            {
                Cost[Root[Min_Value]->value] = Cost[Min_Value] + Root[Min_Value]->weight;
                Parent[Root[Min_Value]->value]=Min_Value;
            }

            else if (Cost[Root[Min_Value]->value] == Cost[Min_Value] + Root[Min_Value]->weight)
            {
                if(Parent[Root[Min_Value]->value] > Min_Value)
                    Parent[Root[Min_Value]->value]=Min_Value;
            }
            Root[Min_Value] = Root[Min_Value]->link;
        }
        Traverse[Min_Value] = 1;
        Min_Value = getMinValue(Cost, Traverse, V);
    }
}

int Print_COST(int Parent[], int i)
{
    while(Parent[i]!=0)
    {
        Print_COST(Parent, Parent[i]);
        printf(" %d",i);
        break;
    }
    if(Parent[i]==0)
        printf("0 %d", i);

}


int main()
{
    int test,V,E,u,v,w;
    scanf("%d",&test);

    for(int k=0; k<test; ++k)
    {
        scanf("%d%d",&V,&E);
        struct node *Root[V], *Head[V];
        int Traverse[V], Cost[V], Parent[V];

        for(int i=0; i<V; ++i)
        {
            Head[i]=NULL;
            Root[i]=NULL;
        }

        for(int b=0;b<E;++b)
        {
            scanf("%d%d%d",&u,&v,&w);
            Input(Head,Root,u,v,w);
        }
    dijkstra_logic(Head, Root, V, Cost, Traverse, Parent);

    for(int i=0; i<V; ++i)
    {
        if(i==0)
            printf("0");
        else if(Parent[i]==-1)
            printf("NIL");
        else
            Print_COST(Parent,i);
        printf("\n");
    }
    }
}
