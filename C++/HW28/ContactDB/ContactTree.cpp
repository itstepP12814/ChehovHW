#include "ContactTree.h"

ContactTree::ContactTree() : root(NULL), sizeOfTree(0)
{
}


ContactTree::~ContactTree()
{
}
string &ContactTree::operator[](const string &index)
{
	Subscriber **current = &root;
	Subscriber *pr = NULL;
	while ((*current) != NULL)
	{
		pr = (*current);
		if ((*current)->name == index)
		{
			return (*current)->number;
		}
		if (index < (*current)->name)
		{
			current = &((*current)->left);
		}
		else
		{
			current = &((*current)->right);
		}
	}
	(*current) = new Subscriber(index);
	(*current)->parent = pr;
	++sizeOfTree;
	return (*current)->number;
}
void ContactTree::insert(const string &index, const string &number)
{
	Subscriber **current = &root;
	Subscriber *pr = NULL;
	while ((*current) != NULL)
	{
		pr = (*current);
		if ((*current)->name == index)
		{
			(*current)->number = number;
		}
		if (index < (*current)->name)
		{
			current = &((*current)->left);
		}
		else
		{
			current = &((*current)->right);
		}
	}
	(*current) = new Subscriber(index);
	(*current)->parent = pr;
	(*current)->number = number;
	(*current)->name = index;
	++sizeOfTree;
}
//изменение номера рекурсивное
void ContactTree::editNumber(const string &index, const string &newNumber, Subscriber *node)
{
	if (node != NULL)
	{
		editNumber(index, newNumber, node->left);
		if (node->name == index)
		{
			node->number = newNumber;
		}
		editNumber(index, newNumber, node->right);
	}
}

//изменение имени рекурсивное
void ContactTree::editName(const string &index, const string &newName, Subscriber *node)
{
	if (node != NULL)
	{
		editName(index, newName, node->left);
		if (node->name == index)
		{
			node->name = newName;
		}
		editName(index, newName, node->right);
	}
}
//надо придумать как сделать поиск по имени рекурсивным, это избавит нас от сложноcтей в случае если имена изменены
//поиск по имени бинарный,
ContactTree::Subscriber *ContactTree::searchByName(const string &index)
{
	Subscriber **current = &root;
	int checker = 0;
	while ((*current) != NULL)
	{
		if ((*current)->name == index)
		{
			cout << "found!" << endl;
			print(*current);
			checker = 1;
			return *current;
		}
		if (index < (*current)->name)
		{
			current = &((*current)->left);
		}
		else
		{
			current = &((*current)->right);
		}
	}
	if (!checker)
	{
		cout << "nothing found" << endl;
		return NULL;
	}
	else return *current;
}
//поиск по номеру рекурсивный
void ContactTree::searchByNumber(const string &num, Subscriber *node)
{
	if (node != NULL)
	{
		searchByNumber(num, node->left);
		if (node->number == num)
		{
			cout << "found!" << endl;
			print(node);
		}
		searchByNumber(num, node->right);
	}
}

void ContactTree::showFromLeft(Subscriber *node)
{
	if (node != NULL)
	{
		if (node->left)
		{
			showFromLeft(node->left);
		}
		print(node);
		if (node->right)
		{
			showFromLeft(node->right);
		}
	}
}
void ContactTree::showFromRight(Subscriber *node)
{
	if (node != NULL)
	{
		showFromRight(node->right);
		print(node);
		showFromRight(node->left);
	}
}

ContactTree::Subscriber *ContactTree::max(Subscriber *node)
{
	if (node != NULL)
	{
		while (node->right != NULL)
		{
			node = node->right;
		}
		return node;
	}
	else return NULL;
}
ContactTree::Subscriber *ContactTree::min(Subscriber *node)
{
	if (node != NULL)
	{
		while (node->left != NULL)
		{
			node = node->left;
		}
		return node;
	}
	else return NULL;
}
ContactTree::Subscriber *ContactTree::next(Subscriber *node)
{
	if (node != NULL && node->right != NULL)
	{
		return min(node->right);
	}
	else return NULL;
}
ContactTree::Subscriber *ContactTree::prev(Subscriber *node)
{
	if (node != NULL && node->left != NULL)
	{
		return max(node->left);
	}
	else return NULL;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ContactTree::deleteContact(const string& index) {
	Subscriber* deletedContact = searchByName(index);//удаляемый контакт
	Subscriber* minFromRightBranch = NULL;//узел следующий по индексу за удаляемым, проще говоря это самый "левый" узел в правой от удаляемого ветки

	if (!deletedContact) { //найден ли вообще удаляемый узел
		cout << "error" << endl;
		return;
	}
	//случай 1 Когда удаляемый элемент просто лист
	if (deletedContact->left == NULL && deletedContact->right == NULL) {
		if (deletedContact == deletedContact->parent->left) {
			//переписываем родителю указатели на путсые в зависимости от того с какой стороны стоял лист
			deletedContact->parent->left = NULL;
			delete deletedContact;
			//мы удалили структуру по указателю, но в самом указателе оказался мусор, принулдительно Выходим из функции
			return;
		}
		else {
			deletedContact->parent->right = NULL;
			delete deletedContact;
			return;
		}
	}
	/*2 случай когда справа и слева есть ветки т.к если два предыдущих условия пройдены значит у нас есть две полноценные ветки
	мы не будем структурно разрущать элемент, а найдем следующий по возрастанию по индексу элемент, перепишем данные из него и удалим "следующий"
	так делается, потому что у этого следующего будет либо оддна дочерняя ветка справа либо вообще ни одной
	проверка условия (deletedContact->right!=NULL && deletedContact->left!=NULL) особо ненужна, т.к в данном случае мы уверены что узел точно не пустой
	и что в нем точно две ветки
	мы точно знаем что у него не будет ветки слева, но может быть ветка справа, а может и не быть;*/
	if (deletedContact->right != NULL && deletedContact->left != NULL) {
		minFromRightBranch = next(deletedContact);//находим следующий по индексу элемент из правой ветки, это будет самый "левый элемент"
		if (minFromRightBranch) {
			deletedContact->name = minFromRightBranch->name;
			deletedContact->number = minFromRightBranch->number;
			if (minFromRightBranch->right != NULL) {
				//если вправа есть ветка проверяем каким этот элемент стоит от роидителя, т.к самый "левый" может стоять справа, если ветка идет отвесно вправо
				//по сути в этом случае "самый левый" будет дочерним от удаляемого
				if (minFromRightBranch == minFromRightBranch->parent->left) {
					minFromRightBranch->parent->left = minFromRightBranch->right;
					minFromRightBranch->right->parent = minFromRightBranch->parent;
					delete minFromRightBranch;
				}
				else {
					minFromRightBranch->parent->right = minFromRightBranch->right;
					minFromRightBranch->right->parent = minFromRightBranch->parent;
					delete minFromRightBranch;
				}
			}
			else {
				//если "следующий" просто лист
				if (minFromRightBranch == minFromRightBranch->parent->left) {
					minFromRightBranch->parent->left = NULL;
				}
				else {
					minFromRightBranch->parent->right = NULL;
				}
				delete minFromRightBranch;
			}
		}
		return;
	}
	//3 если слева от удаляемого узла ничего нет
	if (deletedContact->right != NULL && deletedContact->left == NULL) {
		//Проверяем с какой стороны удаляемый стоит от своего родителя
		if (deletedContact == deletedContact->parent->right) {
			deletedContact->parent->right = deletedContact->right;
			deletedContact->right->parent = deletedContact->parent;
		}
		else {
			deletedContact->parent->left = deletedContact->right;
			deletedContact->right->parent = deletedContact->parent;
		}
		delete deletedContact;
	}
	else {
		//4 случай когда справа от удаляемого узла ничего нету
		//проверяем с какой стороны удаляемый стоит от родителя
		if (deletedContact == deletedContact->parent->right) {
			deletedContact->parent->right = deletedContact->left;
			deletedContact->left->parent = deletedContact->parent;
		}
		else {
			deletedContact->parent->left = deletedContact->left;
			deletedContact->left->parent = deletedContact->parent;
		}
		delete deletedContact;
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ContactTree::print(Subscriber *node)
{
	if (node->parent)
	{
		cout << "parent " << node->parent->name << endl;
	}
	cout << "name " << node->name << endl;
	cout << "number " << node->number << endl << endl;
}

ContactTree::Subscriber *getRoot(const ContactTree &A)
{
	return A.root;
}
void ContactTree::saveAtFile(const string &fileName, const string &mode)
{
	/*тут костыль т.к функция самой записи в файл рекурсивная, значит мы будем файл постоянно переоткрыввать, а значит нам нужно использовать флаг ofstream::app
	для записи в конец файла, иначе мы увидим лишь последюю строчку в базе, а т.к мы испотльзуем для записи флажок app возникает необходимость
	перед запуском рекурсивной записи очистить прыдыдущий файл, если он существует*/
	ofstream fout(fileName, ofstream::trunc);
	saveR(root, fileName, mode);
}
void ContactTree::saveR(Subscriber *node, const string &fileName, const string &mode) //рекурсивный обход дерева и запись в файл
{
	if (node)
	{
		saveR(node->left, fileName, mode);
		if (mode == "t" || mode == "T")
		{
			ofstream fout(fileName, ofstream::out | ofstream::app);//ключ app говорит что мы открываем файл для записи в конец файла
			fout << "name " << node->name << endl;
			fout << "number " << node->number << endl << endl;
		}
		else
		{
			if (mode == "b" || mode == "B")
			{
				ofstream fout(fileName, ofstream::binary | ofstream::app);//ключ app говорит что мы открываем файл для записи в конец файла
				fout << node->name << endl;
				fout << node->number << endl;
			}
		}
		saveR(node->right, fileName, mode);
	}
}
void ContactTree::readFromFile(const string &fileName)
{
	ifstream fin(fileName);
	string name;
	string number;
	if (!fin.is_open()) //если файл не открыт
	{
		cout << "error read file!" << endl;
	}
	else
	{
		while (!fin.eof())
		{
			//можно еще было использовать getline(fin, name)
			fin >> name;
			fin >> number;
			insert(name, number);
		}
		fin.close();
	}
}