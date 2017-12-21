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
	Node *tmp = list2.head;
	head = NULL;

	while (tmp != NULL)
	{
		InsertToTail(tmp->data);
		tmp = tmp->next;
	}
}

List& List::operator=(const List& list2)
{
	if (this != &list2)
	{
		Node *tmp = list2.head;
		head = NULL;

		while (tmp != NULL)
		{
			InsertToTail(tmp->data);
			tmp = tmp->next;
		}
	}
	return *this;
}

List::~List()
{
	while (head != NULL)
	{
		Node *tmp = head->next;
		delete head;
		head = tmp;
	}
	delete head;
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

	while ((tmp != NULL) && (tmp->next != NULL))
	{
		tmp = tmp->next;
	}

	if (tmp != NULL)
	{
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
	Node *tmp1 = head, *tmp2;

	if (node != NULL)
	{
		while (((tmp1 != NULL) && (tmp1->next != NULL)) && (tmp1 != node))
		{
			tmp1 = tmp1->next;
		}

		if ((tmp1 != NULL) && (tmp1->next != NULL))
		{
			tmp2 = tmp1->next;
			tmp1->next = new Node;
			tmp1->next->data = d;
			tmp1->next->next = tmp2;
		}
	}
	else
	{
		if (head == NULL)
			throw - 1;
	}
}

void List::Delete(const DataType& d)
{
	Node *tmp1 = head, *tmp2;

	if ((head != NULL) && (head->data != d))
	{
		while (((tmp1 != NULL) && (tmp1->next != NULL)) && (tmp1->data != d))
		{
			tmp2 = tmp1;
			tmp1 = tmp1->next;
		}

		if ((tmp1 != NULL) && (tmp1->next != NULL))
		{
			tmp2->next = tmp1->next;
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
	this->~List();
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
	//int i = 0, s = GetSize();
	//Node *tmp = head, **n = new Node *[s];

	//while (tmp != NULL)
	//{
	//	n[i] = tmp; n[i]->next = NULL;
	//	tmp = tmp->next; i++;
	//}

	//tmp = head;
	//while (tmp->next != NULL)
	//{
	//	tmp = tmp->next;
	//}

	//head = tmp;
	//for (int j = s - 1; j >= 0; j--)
	//{
	//	tmp->next = n[j];
	//}

	//head->next = NULL;
}

List List::Merge(Node* node, const List& list2)
{
	//List l1(*this), l2(list2), l3;
	//Node *tmp1 = l1.head, *tmp2 = l2.head;

	//while (tmp2->next != NULL)
	//	tmp2 = tmp2->next;

	//while (((tmp1 != NULL) && (tmp1->next != NULL)) && (tmp1 != node))
	//{
	//	tmp1 = tmp1->next;
	//}

	//if ((tmp1 != NULL) && (tmp1->next != NULL))
	//{
	//	tmp2->next = tmp1->next;
	//	tmp1->next = l2.head;
	//}

	////l3 = *this;
	////*this = l1;
	return *this;
}

List List::Merge(const List& list2)
{
	return *this;
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
		if (i == s1)
			return true;
	}
	else
		return false;
}