#include<iostream>
using namespace std;

struct Simpul{
	int a;
	Simpul* Left;
	Simpul* Right;
};
typedef Simpul* pointer;
typedef pointer Tree;

void createTree(Tree& Root){
	Root = 0;
}

void createelement(pointer& pBaru){
	pBaru = new Simpul;
	cout << "Masukan Angka : "; cin >> pBaru->a;
	pBaru->Left = 0;
	pBaru->Right = 0;
}

void insertTree(Tree& Root, pointer pBaru){
	if (Root == 0){
		Root = pBaru;
	}
	else if (pBaru->a < Root->a) {
		insertTree(Root->Left, pBaru);
	}
	else if(pBaru->a > Root->a){
		insertTree(Root->Right, pBaru);
	}
	else{
		cout << "Data sudah ada\n";
 	}
}

void Preorder(Tree Root){
	if (Root != 0){
		cout << Root->a<< " ";
		Preorder(Root->Left);
		Preorder(Root->Right);
	}
}

void Inorder(Tree Root){
	if (Root != 0){
		Inorder(Root->Left);
		cout << Root->a<< " ";
		Inorder(Root->Right);
	}
}

void Postorder(Tree Root){
	if (Root != 0){
		Postorder(Root->Left);
		Postorder(Root->Right);
		cout << Root->a<< " ";
	}
}

int main(){
	pointer pBaru;
	Tree Root;
	int pil;
	
	
	createTree(Root);
	
	do{
	cout << endl;
	cout << "1. Insert Angka\n";
	cout << "2. Pre Order\n";
	cout << "3. In Order\n";
	cout << "4. Post Order\n";
	cout << "5. Exit\n";
	cout << "Pilih : "; cin >>pil;
	
		switch (pil){
			case 1 : 
				createelement(pBaru);
				insertTree(Root, pBaru);
				break;
			case 2 :
				Preorder(Root);
				break;
			case 3 :
				Inorder(Root);
				break;
			case 4 :
				Postorder(Root);
				break;
			}		
	}while(pil != 5);

}
