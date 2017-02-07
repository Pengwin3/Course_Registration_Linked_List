 #include <utility>

#include "Schedule.h"

using namespace std::rel_ops;

/**
 *
 */
Schedule::Schedule()
    :head(nullptr),
     tail(nullptr),
     totalCredits(0)
{
}

Schedule::Schedule(const Schedule &src)
 :head(nullptr),
  tail(nullptr),
  totalCredits(0)
{
 Node* it = src.head;
 while (it!= nullptr)
   {  this->add(it->data);
     it = it->next; }
}

Schedule::~Schedule()
{}

 /**
 *
 */
bool Schedule::add(Course course)
{
  return true;
}

/**
 *
 */
void Schedule::display(std::ostream& outs) const
{
    Node* it = head;

    outs << "  (" << totalCredits << " Total Credits)" << "\n";

    while (it != nullptr) {
        // oops I forgot to remove most of this function

        it = it->next;
    }
}



/**
 * You may ignore this function, or use it, the choice is yours
 */
void Schedule::deAllocateList(){}

/**
 * You may ignore this function, or use it, the choice is yours
 */
void Schedule::copyList(const Schedule& rhs)
{

}
