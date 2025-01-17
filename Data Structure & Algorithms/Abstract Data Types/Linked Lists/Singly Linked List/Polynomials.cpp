#include <Singly_Linked_List.h>
#include <iostream>
using namespace std;

class Polynomial;
class Term
{
private:
    double coeff;
    int exp;
    friend class Polynomial;

public:
    Term(double coeff = 0.0, int exp = 0)
    {
        this->coeff = coeff;
        this->exp = exp;
    }
    bool operator==(const Term &rhs) const
    {
        return this->coeff == rhs.coeff && this->exp == rhs.exp;
    }
    friend ostream &operator<<(ostream &os, const Term &term)
    {
        os << endl;
        os << "Term: " << "(" << term.coeff << " " << term.exp << ")";
        return os;
    }
};
;
class Polynomial
{
private:
    SLinkedList<Term> *terms;

public:
    Polynomial()
    {
        this->terms = new SLinkedList<Term>();
    }
    ~Polynomial()
    {
        this->terms->clear();
    }
    void insertTerm(const Term &term);
    void insertTerm(double coeff, int exp);
    void print()
    {
        SLinkedList<Term>::Iterator it;
        cout << "[";
        for (it = this->terms->begin(); it != this->terms->end(); it++)
            cout << (*it);
        cout << endl
             << "]";
    }
};

void Polynomial::insertTerm(const Term &term)
{
    this->insertTerm(term.coeff, term.exp);
}

void Polynomial::insertTerm(double coeff, int exp)
{
    if (coeff == 0)
        return;

    if (this->terms->empty())
    {
        this->terms->add(Term(coeff, exp));
        return;
    }

    for (int i = 0; i < terms->size(); i++)
        if (this->terms->get(i).exp == exp)
        {
            if (this->terms->get(i).coeff + coeff == 0)
            {
                this->terms->removeAt(i);
                return;
            }
            else
            {
                this->terms->set(i, Term((this->terms->get(i).coeff) + coeff, exp));
                return;
            }
        }
    for (int j = 0; j < this->terms->size(); j++)
        if (this->terms->get(j).exp < exp)
        {
            this->terms->add(j, Term(coeff, exp));
            return;
        }
    this->terms->add(Term(coeff, exp));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    clock_t start = clock();
    SLinkedList<int> list;

    int size = 10;
    for (int idx = 0; idx < size; idx++)
        list.add(idx);

    SLinkedList<int>::Iterator it;
    int expvalue = 0;
    for (it = list.begin(); it != list.end(); it++)
    {
        assert(*it == expvalue);
        expvalue += 1;
    }
}