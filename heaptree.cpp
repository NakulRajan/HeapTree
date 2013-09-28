#include "BinaryHeap.h"
using namespace std;

int main()
{  
	char choice;
	BinaryHeap H1;
	BinaryHeap H2;
	int i;
	
	while (1) {
	
	cout << endl << "Binary Heap Calculator" << endl;
    cout << "1.Add -a\t 2.Display -d" <<endl;
	cout << "3.Clear -c\t 4.Copy -o"<<endl;
	cout << "5.Switch -s\t 6.Union -u" << endl;
	cout << "7.Intersection -i\t 8.Remove -r" << endl;	
	cout << "9.Quit -q" << endl << endl;
		
	cin  >> choice;
	switch (choice) {
		case 'a':
			int element;
			cout << "Insert an Integer Element into Binary Heap:" <<endl;
			cin >> element;
			H1.insert(element);
			break;
		case 'd':
			cout << endl << "H1:" << "    ";
			H1.Display();
			cout << endl << "H2:" << "    "; 
			H2.Display();
			cout << endl << "-----------------------------------------------" << endl;
			break;
		case 'o':
			cout << "Copy Tree:" << endl;
			H2.setroot(H2.copy((H1.getroot())));
			cout << "H1:" << "    "; 
			H1.Display();
			cout << endl;
			cout << "H2:" << "    "; 
			H2.Display();
			cout << endl << "-----------------------------------------------" << endl;
			cout << endl;
			break;
		case 's':
			cout << "Switch Tree:" << endl;
			H1.switchtree(&H2);
			cout << "H1:" << "    "; 
			H1.Display();
			cout << endl;
			cout << "H2:" << "    "; 
			H2.Display();
				break;
			cout << endl << "-----------------------------------------------" << endl;
		case 'c':
			cout << "Clear Tree:" << endl;
			H1.clear();
			cout << "H1:" << "   "; 
			H1.Display();
			cout << endl << "-----------------------------------------------" << endl;
			break;
		case 'u':
			cout << "Tree Union:" << endl;
			H1.treeUnion(&H2);
			break;
		case 'i':
			cout << "Tree Intersection:" << endl;
			H1.treeIntersection(&H2);
			break;
		case 'r':
			int element2;
			cout << "Enter the element you want to remove" << endl;
			cin >> element2;
			H1.remove(element2);
			break;
		case 'q':
			exit(1);
				break;
		default:cout << "Please enter a valid choice" <<endl;
			break;
	}
	}
}
