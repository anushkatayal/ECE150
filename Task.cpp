//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//

#include <stdlib.h>
using namespace std;
//////////////////////////////////////////////////////////////
//
// local #includes and function declarations; do not remove
//

#ifndef MARMOSET_TESTING
#include <iostream>
#endif

//////////////////////////////////////////////////////////////
//
// struct definitions 
//
#ifndef MARMOSET_TESTING

enum TaskType{LAUNDRY, DISHES, MAKE_BED, VACUUM, MOP_FLOOR, MOW_LAWN};

struct Task 
{
	TaskType type; // Laundry, dishes, etc.
	int taskID;
	char* description;
};

struct TaskQueue
{
	Task* task;
	TaskQueue* nextInQueue;
};

#endif

//////////////////////////////////////////////////////////////
//
// Function declarations; do not remove
//

bool enqueue(TaskQueue*& queue, const Task& task);
const Task* dequeue(TaskQueue*& queue);

//////////////////////////////////////////////////////////////
//
// Function definitions. PLEASE USE HELPER FUNCTIONS
//

bool enqueue(TaskQueue*& queue, const Task& task)
{
	return false;
}

const Task* dequeue(TaskQueue*& queue)
{
	return NULL;
}

//////////////////////////////////////////////////////////////
//
// Test Driver
//
// Do not remove the #ifndef and its associated #endif
//
#ifndef MARMOSET_TESTING

int main(){
	// Some test driver code here ....
	cout << endl << "Implement some more appropriate tests in main()" << endl << endl;
	
	char sampleDescription[] = "sample description";

	Task task1 =
	{
		.type = LAUNDRY,
		.taskID = 1,
		.description = sampleDescription
	};

	TaskQueue* p_queue = new TaskQueue;
	p_queue->task = NULL;
	p_queue->nextInQueue = NULL;

	bool enqueueSuccess = enqueue(p_queue, task1);
	if(enqueueSuccess)
		cout << "task1 enqueued successfully" << endl << endl;
	else
		cout << "enqueue() failed" << endl << endl; 

	const Task* p_firstTaskInQueue = dequeue(p_queue);
	
	if (p_firstTaskInQueue)
	{
		cout << "Dequeue successful..." << endl;
		cout << "Type: " << p_firstTaskInQueue->type << endl;
		cout << "Task ID: " << p_firstTaskInQueue->taskID << endl;
		cout << "Description: " << p_firstTaskInQueue->description << endl;
	}
	else
		cout << "dequeue() failed" << endl;

	delete p_queue;
	
	return 0;
}
#endif

