#include <iostream>
#include <sys/stat.h>

using namespace std;

struct Node
{
    int data[1000][1000];
    Node *link;
};
typedef Node* nodePtr;

void insert(nodePtr& head)
{
    nodePtr tempPtr;
    tempPtr = new Node;
    tempPtr->link=head;
    head = tempPtr;
}

void print_list(nodePtr& head)
{
    nodePtr tmp;
    tmp = head;

    while (tmp->link != NULL)
    {
        for (int i = 0; i < 1000; i++)
        {
            for (int j = 0; j < 1000; j++)
            {
                cout<<tmp->data[i][j]<<endl;
            }
            
        }
        tmp = tmp->link;
    }
}

long GetFileSize(string filename)
{
    struct stat stat_buf;
    int rc = stat(filename.c_str(), &stat_buf);
    return rc == 0 ? stat_buf.st_size : -1;
}

int main(int argc, char** argv)
{
    int size = stoi(argv[1]);
    int bound;
    cout<<"Proszę podać ograniczenie rozmiaru pliku (w bajtach): ";
    cin>>bound;
    nodePtr head;
    head = new Node;
    while (GetFileSize("lab_4_2.cpp") <= bound)
    {
        for (int i=0; i<size; i++)
        {
            getchar();
            insert(head);
        }
        cout<<"Zakończenie działania programu"<<endl;
        break;
        //print_list(head);
    }
    return 0;
}
