#include <iostream>

template<typename T>
struct node{
    T data;
    struct node* next;
};

template<typename T>
struct list{
    struct node<T> *head;
    struct node<T> *tail;
    struct node<T> *cur;
};

template<typename T>
class linked_list{
    public:
    linked_list(){
        List = new list<T>;
        List->head = NULL;
        List->tail = NULL;
        List->cur = NULL;
    }

    void push_link(T data){
        struct node<T>* newNode = new node<T>;
        newNode->data = data;
        newNode->next = NULL;

        if (List->head == NULL)
            List->head = newNode;
        else
            List->tail->next = newNode;
        
        List->tail = newNode;
    }

    ~linked_list(){
        if(List->head == NULL)
            std::cout <<"Empty...\n";
        else{
            struct node<T>* delNode =  List->head;
            struct node<T>* delNextNode = List->head->next;
            std::cout << "\nDelete Linked data: \n";
            std::cout << "("<< delNode <<", "<<delNode->data << ") \n";
            delete delNode;
            while(delNextNode != NULL){
                delNode = delNextNode;
                delNextNode = delNode->next;
                std::cout << "("<< delNode <<", "<<delNode->data << ") \n";
                delete delNode;
            }
        }
    }


    void print_link(){
        if (List->head == NULL)
            std::cout <<"Empty...\n";
        else{
            std::cout << "\nLINKED DATA PRINT: \n";
            List->cur = List->head;
            std::cout << "("<< List->cur <<", "<<List->cur->data << ") \n";
            while(List->cur->next != NULL){
                List->cur = List->cur->next;
                std::cout << "("<< List->cur <<", "<<List->cur->data << ") \n";
            }
            std::cout <<"\n";
        }
    }

    private:
    struct list<T>* List;
};



int main(){

    linked_list<int> linked;
    for(int i = 0 ; i < 100 ; ++i)
        linked.push_link(5*i);
    //linked.push_link(15);
    //linked.push_link(25);

    linked.print_link();


    return 0;
}