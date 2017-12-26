#include "list.h"

Node::Node(DataType d, Node* n)
{
	data = d;
	next = n;
}

Node::Node(const Node& node2)
{
	data = node2.data;
	next = node2.next;
}

bool Node::operator==(const Node& node2) const
{
	if ((data == node2.data) && (next == node2.next))
		return true;
	else
		return false;
}

List::List()
{
	head = NULL;
}

List::List(const List& list2)
{
	head = NULL;
	Node *tmp = list2.head, *tmp1 = head;

	while (tmp != NULL)
	{
		if (tmp1 != NULL)
		{
			InsertAfter(tmp1, tmp->data);
			tmp1 = tmp1->next;
		}
		else
		{
			tmp1 = new Node;
			tmp1->next = NULL;
			tmp1->data = tmp->data;
			head = tmp1;
		}
		tmp = tmp->next;
	}
}

List& List::operator=(const List& list2)
{
	if (this != &list2)
	{
		Clean();

		head = NULL;
		Node *tmp = list2.head, *tmp1 = head;

		while (tmp != NULL)
		{
			if (tmp1 != NULL)
			{
				InsertAfter(tmp1, tmp->data);
				tmp1 = tmp1->next;
			}
			else
			{
				tmp1 = new Node;
				tmp1->next = NULL;
				tmp1->data = tmp->data;
				head = tmp1;
			}
			tmp = tmp->next;
		}
	}
	return *this;
}

List::~List()
{
	Clean();
}

void List::InsertToHead(const DataType& d)
{
	Node* tmp = new Node;

	tmp->next = head;
	tmp->data = d;
	head = tmp;

}

void List::InsertToTail(const DataType& d)
{
	Node *tmp = head;

	if (tmp != NULL)
	{

		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}


		tmp->next = new Node;
		tmp->next->next = NULL;
		tmp->next->data = d;
	}
	else
	{
		tmp = new Node;
		tmp->next = NULL;
		tmp->data = d;
		head = tmp;
	}
}

void List::InsertAfter(Node* node, const DataType& d)
{
	Node *tmp1 = node, *tmp2;

	if (node != NULL)
	{
		tmp2 = tmp1->next;
		tmp1->next = new Node;
		tmp1->next->data = d;
		tmp1->next->next = tmp2;
	}
	else
	{
		if (head == NULL)
			throw - 1;
	}
}

void List::Delete(const DataType& d)
{
	Node *tmp1 = head, *tmp2 = NULL;

	if (head != NULL)
	{
		while ((tmp1 != NULL)  && (tmp1->data != d))
		{
			tmp2 = tmp1;
			tmp1 = tmp1->next;
		}

		if (tmp1 != NULL)
		{
			if (tmp2 != NULL)
				tmp2->next = tmp1->next;
			if (tmp1 == head)
				head = tmp1->next;
			delete tmp1;
		}
	}
	else
		head = NULL;

}

Node* List::Search(const DataType& d)
{
	Node *tmp = head;

	while ((tmp != NULL) && (tmp->data != d))
	{
		tmp = tmp->next;
	}

	if (tmp != NULL)
	{
		return tmp;
	}
	else
		return NULL;
}

void List::Clean()
{
	while (head != NULL)
	{
		Node *tmp = head->next;
		delete head;
		head = tmp;
	}
	delete head;
}

int List::GetSize()
{
	Node *tmp = head;
	int s = 0;

	while (tmp != NULL)
	{
		s++;
		tmp = tmp->next;
	}

	return s;
}

Node* List::GetHead()
{
	return head;
}

void List::Inverse()
{
	if (GetSize() > 2)
	{
		Node *tmp1 = head, *tmp2 = head->next, *tmp3;

		tmp1->next = NULL;

		while (tmp2 != NULL)
		{
			tmp3 = tmp2->next;
			tmp2->next = tmp1;
			tmp1 = tmp2;
			tmp2 = tmp3;
		}
		head = tmp1;
	}
	else
		if (GetSize() == 2)
		{
			Node *tmp = head->next;
			tmp->next = head;
			head->next = NULL;
		}			
}

List List::Merge(Node* node, const List& list2)
{
	if (node != NULL)
	{
		List l3;
		Node *tmp1 = head, *tmp2 = list2.head;

		while ((tmp1 != NULL) && (node->next != tmp1))
		{
			l3.InsertToTail(tmp1->data);
			tmp1 = tmp1->next;
		}

		while (tmp2 != NULL)
		{
			l3.InsertToTail(tmp2->data);
			tmp2 = tmp2->next;
		}

		while (tmp1 != NULL)
		{
			l3.InsertToTail(tmp1->data);
			tmp1 = tmp1->next;
		}

		return l3;
	}
	else
		return *this;
}

List List::Merge(const List& list2)
{
	List l3;
	Node *tmp1 = head, *tmp2 = list2.head;

	while (tmp1 != NULL)
	{
		l3.InsertToTail(tmp1->data);
		tmp1 = tmp1->next;
	}

	while (tmp2 != NULL)
	{
		l3.InsertToTail(tmp2->data);
		tmp2 = tmp2->next;
	}

	return l3;
}

bool List::operator==(const List& list2) const
{
	Node *tmp1 = head, *tmp2 = list2.head;
	int s1 = 0, s2 = 0, i = 0;

	while (tmp1 != NULL)
	{
		s1++;
		tmp1 = tmp1->next;
	}
	while (tmp2 != NULL)
	{
		s2++;
		tmp2 = tmp2->next;
	}

	if (s1 == s2)
	{
		DataType *l1 = new DataType[s1], *l2 = new DataType[s1];

		tmp1 = head; tmp2 = list2.head;
		while (tmp1 != NULL)
		{
			l1[i++] = tmp1->data;
			tmp1 = tmp1->next;
		}
		i = 0;
		while (tmp2 != NULL)
		{
			l2[i++] = tmp2->data;
			tmp2 = tmp2->next;
		}
		i = 0;
		for (int j = 0; j < s1; j++)
			if (l1[j] == l2[j])
				i++;

		delete[] l1;
		delete[] l2;

		if (i == s1)
			return true;
		else
			return false;
	}
	else
		return false;
}

ostream& operator<<(ostream& os, const List& l)
{
	Node *tmp = l.head;

	while (tmp != NULL)
	{
		os << "|" << tmp->data << "|" << tmp << "|" << "--->";
		tmp = tmp->next;
	}
	os << " NULL";

	return os;
}