#include<iostream>
#include<string>
using namespace std;

class Node //�����ڵ�������������ź���ĸ 
{
public:

	char word;
	Node* next;
	Node()
	{
		next = NULL;
	}
};

class Stack//ջ������ 
{
public:
	Node *top;
	Node *base;
	char topword;
	
	Stack()
	{
		top=base = new Node();
	}
	
	~Stack()
	{}
	
	bool push(char c)
	{
		Node *temp = new Node();
		if(temp == NULL)
		{
			cout<<"Error,Overflow!"<<endl;
			return false;
		}
		
		temp->next = top;
		temp->word = c;
		top = temp;
		topword = c;
		return true;
	}
	
	void pop(char &e)
	{
		if( top == base)
		{
			return;
		}
		
		Node *delete_node = top;
		e = top->word;
		top = top->next;
		
		delete delete_node;
		topword = top->word;
		return;
	}
	
	bool IsEmpty() 
	{
		if( top == base )
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
};

class Queue
{
public:
	Node *head;
	Node *tail;
	
	Queue()
	{
		head=tail = new Node();
	}
	
	~Queue()
	{
		
	}
	
	bool IsEmpty()
	{
		if( head == tail)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	bool InQueue(char c)
	{	
		Node *temp = new Node();
		{
			if( temp == NULL )
			{
				cout<<"Error,Overflow!"<<endl;
				return false;
			}
			else
			{
				temp->word = c;
				tail->next = temp;
				tail = temp;
				
				return true;
			}
		}
	}
	
	bool OutQueue(char &c)
	{
		if(head == tail)
		{
			return false;
		}
		else
		{
			Node *p = head->next;
			c = p->word;
			head->next = p->next;
			delete p;
			return true;
		}
	}
	
	void Translate()
	{
		Node *temp = head->next;
		char c;
		while( temp!= NULL )
		{
			c=temp->word;
			switch(c)
			{
				case 't':cout<<"��";break;
				case 'd':cout<<"��";break;
				case 's':cout<<"��";break;
				case 'a':cout<<"һֻ";break;
				case 'e':cout<<"��";break;
				case 'z':cout<<"׷";break;
				case 'g':cout<<"��";break;
				case 'x':cout<<"��";break;
				case 'n':cout<<"��";break;
				case 'h':cout<<"��";break;
				default:
					cout<<c;break; 
			}
			temp = temp->next; 
		}
		return;
	}
	
	void OutputAll()
	{
		Node *temp = head->next;
		while( temp !=NULL )
		{
			cout<<temp->word;
			temp = temp->next;
		}
		cout<<endl;
	}
	
	void InA()
	{
		InQueue('s');
		InQueue('a');
		InQueue('e');
		
		return;
	}
	
	void InB()
	{
		InQueue('t');
		InA();
		InQueue('d');
		InA();
		
		return;
	}
};

void deal(Stack &S)
{
	Stack T,QQ;
	char ch,c;
	S.pop(ch);
	if(ch=='(')
	{
		deal(S);
		S.pop(ch);
	}
	if(ch==')')
	{
		return;
	}
	while(ch !=')')
	{
		S.pop(c);
		if(c=='(')
		{
			deal(S);
		}
		else if(c==')')
		{
			break;
		}
		else
		{
			T.push(ch);
			T.push(c);
	    }
	}
	T.push(ch);
	while(!T.IsEmpty())
	{
		T.pop(ch);
		QQ.push(ch);
	}
	while(!QQ.IsEmpty())
	{
		QQ.pop(ch);
		S.push(ch);
	}
	return;
}

int main()
{
	Stack S;//SΪԭʼջ 
	Queue Q;
	char c,ch;
	
	string s;
	cout<<"������ħ������"<<endl;
	cin>>s;
	//�ж�ħ�������Ƿ���� 
{
	bool flag=true;
	int lbracket = 0,rbracket = 0;
	int n = s.length();
	for(int i = 0; i < n; i++)
	{
		if( s[i] == '(')
		{
			lbracket++;
		}
		if( s[i] == ')')
		{
			rbracket++;
		}
	}
	if(lbracket!=rbracket)
	{			
		cout<<"���Ų�ƥ��"<<endl;
		return 0;
	}
	for(int i = n-1; i>=0; i--)
	{
		S.push(s[i]);
	}
}

	cout<<endl;
	
	while(!S.IsEmpty())
	{
		S.pop(ch);
		if(ch == 'A')
		{
			Q.InQueue('s');
			Q.InQueue('a');
			Q.InQueue('e');
		}
		else if(ch == 'B')
		{
			Q.InQueue('t');
			Q.InQueue('s');
			Q.InQueue('a');
			Q.InQueue('e');
			Q.InQueue('d');
			Q.InQueue('s');
			Q.InQueue('a');
			Q.InQueue('e');
		}
		else if(ch=='(')
		{
			deal(S);
		}
		else
		{
			Q.InQueue(ch);
		}
	}
	
	cout<<"��ʼħ�����Խ���Ϊ:"<<endl;
	Q.OutputAll();
	cout<<endl;
	
	cout<<"����ħ�����Խ���Ϊ:"<<endl;
	Q.Translate(); 
	cout<<endl;
	
	return 0;
}
