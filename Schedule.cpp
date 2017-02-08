 #include <utility>

#include "Schedule.h"

using namespace std::rel_ops;

/**
 *
 */
Schedule::Schedule()
        : head(nullptr),
        tail(nullptr),
        totalCredits(0)
{
}

Schedule::Schedule(const Schedule &src)
        : head(nullptr),
        tail(nullptr),
        totalCredits(0)
{
        Node* it = src.head;
        while (it!= nullptr)
        {  this->add(it->data);
           it = it->next; }
}

Schedule::~Schedule()
{
        // Deallocate the Linked List
        Node* it = this->head;

        while (it != nullptr) {
                Node* prev = it;

                it = it->next;
                delete prev;
        }
        it = nullptr;

        this->head = nullptr;
        this->tail = nullptr;
        // End Linked List Deallocation
}

bool Schedule::add(Course course)
{
        if(head==nullptr)
        {
                head = new Node(course);
                tail = head;
                totalCredits = course.getCredits();

                return true;
        }
        else
        {
                bool kill = false;
                Node *present = head;
                if(totalCredits + course.getCredits() > CREDIT_LIMIT)
                {
                        return false;
                }

                while(present != nullptr && kill == false)
                {
                        if(course == present->data)
                        {
                                kill = true;
                        }

                        present = present->next;
                }
                if(kill == true)
                {
                        return false;
                }
                else
                {
                        tail->next = new Node(course);
                        tail = tail->next;
                        totalCredits += course.getCredits();

                        return true;
                }
                return false;
        }
}

void Schedule::display(std::ostream& outs) const
{
        Node* it = head;

        outs << "  (" << totalCredits << " Total Credits)" << "\n";

        while (it != nullptr) {
                outs << "  - "
                     << it->data.getCredits() << " Credits - "
                     << it->data.getNumber() << " (CRN "
                     << it->data.getCrn() << ")\n";

                it = it->next;
        }
}

void Schedule::deAllocateList()
{
        // Deallocate the Linked List
        Node* it = this->head;

        while (it != nullptr) {
                Node* prev = it;

                it = it->next;
                delete prev;
        }
        it = nullptr;

        this->head = nullptr;
        this->tail = nullptr;
        // End Linked List Deallocation
}

/**
 * You may ignore this function, or use it, the choice is yours
 */
void Schedule::copyList(const Schedule& rhs)
{
  // I choose to ignore it
}
