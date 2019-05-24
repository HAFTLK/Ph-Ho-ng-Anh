#include<iostream>
#include<queue>
#include<math.h>
using namespace std;
//// tao node moi
struct node
{
	int data;
	struct node *pleft;
	struct node *pright;
};
typedef node* tree;

void init(tree &l)
{
	l = NULL;
}
// them node 
void insert(tree &l, int x)
{
	if (l == NULL)
	{
		node *p = new node;
		p->data = x;
		p->pleft = p->pright = NULL;
		l = p;
	}
	else
	{
		if (l->data > x)
		{
			insert(l->pleft, x);
		}
		else if (l->data < x)
		{
			insert(l->pright, x);
		}
	}
}
// tao cay
void createtree(tree &t)
{
	int choose;
	init(t);
	do {
		cout << "\n1.Nhap so: ";
		cout << "\n2.Thoat";
		cout << "\nNhap lua chon: "; cin >> choose;
		if (choose == 1)
		{
			int x;
			cout << "\nNhap x: "; cin >> x;
			insert(t, x);// th�m gi� tri vao cay
		}
	} while (choose != 0);
}

void NLR(tree l)
{
	if (l != NULL)
	{
		cout << l->data << "   ...  ";
		NLR(l->pleft);
		NLR(l->pright);
	}
}
void LRN(tree &l)
{
	if (l != NULL){
		cout << l->data <<"...";
		LRN (l->pright);
		LRN (l->pleft);
		}
	}	
// t�m node 
node* search(tree l, int x)
{
	if (l == NULL)
	{
		return NULL;
	}
	else
	{
		if (l->data > x)
		{
			search(l->pleft, x);
		}
		else if (l->data < x)
		{
			search(l->pright, x);
		}
		else
		{
			return l;
		}
	}
}


void delnode(tree &l, int x)
{
	if (l == NULL)
	{
		return;
	}
	else
	{
		if (l->data > x)
		{
			delnode(l->pleft, x);
		}
		else if(l->data<x)
		{
			delnode(l->pright, x);
		}
		else
		{
			node *p = l;
			if (l->pleft == NULL)
			{
				l = l->pright;
			}
			else if(l->pright==NULL)
			{
				l = l->pleft;
			}
			else
			{

			
			
			}

			delete p;
       }
   }

}

////////////////Th�m phan tu 
void them(tree &l, int x)
{
	if (l == NULL)
	
	{
		node *p = new node;
		p->data = x;
		p->pleft = p->pright=NULL;
		l = p;
	
	}
	else
	{
		if (l->data > x)
		{
			them(l->pleft, x);
		}
		else if(l->data<x)
		{
			them(l->pright, x);
		}
		else
		{
			node *l = new node;
			if (l->pleft == NULL)
			{
				l->data = x;
				l = l->pright;
				
			}
			else if(l->pright==NULL)
			{
				l->data = x;
				l = l->pleft;
			}
			

		}
	}
}
//dem so nut co 2 con 
int GetDNodeNum(tree l) {
int n;
if (l == NULL)
return 0;
if ((l->pleft == NULL) && (l->pright == NULL))
return 0;
if ((l->pleft) && (l->pright))
n = 1;
else
n = 0;
n = n + GetDNodeNum(l->pleft) +GetDNodeNum(l->pright);
return n;
}
// viet ham liet ke cac so  nguyen to co the xuat hien trong cay
int Prime(tree l, int x){
	
	int Sum;
	{
	for(int i =1; i<=sqrt(x); i++)
	{
		if(x%i==0)
	return 1;
	}
		{
		for(int i=1; i<=sqrt(x); i++){
			Sum =0;
			Sum = Sum+x;
			return 0;
			}
			return 0;
}
}

}


int main()
{
	tree l;
	createtree(l);
	cout << "\nDuyet theo NLR: \n";
	NLR(l);
	cout<<"\nDuyet theo LRN: \n";
	LRN(l);
	int x;
	cout << "\nNhap node can tim : "; cin >> x;
	node *u = search(l, x);
	if (u == NULL)
	{
		cout << "\nKhong tim thay node xin kiem tra lai!";
	}
	else
	{
		cout << "\nNo de ban can tim co trong cay cam on!";
	}
int g;
	cout << "\nNhap phan tu ban muon xoa!"; cin >> g;
	delnode(l, g);
	cout << "\nCay sau khi xoa!\n";
	NLR(l);


d: int h;
	cout << "\nNhap phan tu ban them!"; cin >> h;
	them(l, h);
	cout << "\nCay sau khi them!\n";
	NLR(l);
	goto d;
        system("pause");
	int n;
	cout<<"\nSo luong nut co 2 con cua cay: \n"; 
	GetDNodeNum(l);
	
int f;
cout<<"\nSo nguyen to co the xuat hien: \n";
cout<<"\nTong cac so nguyen to da tim duoc la: ";
 Prime(l, x);

system("pause");
	return 0;
}
