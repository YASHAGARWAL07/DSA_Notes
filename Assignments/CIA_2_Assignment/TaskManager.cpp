#include <iostream>
#include <string>

using namespace std;

struct Task
{
    int taskID;
    string description;
    string status; // "pending" or "completed"
    Task *next;
};

struct TaskManager
{
private:
    Task *head;        // Active tasks
    Task *historyHead; // Deleted tasks (History)

public:
    // Constructor
    TaskManager()
    {
        head = NULL;
        historyHead = NULL;
    }

    // Check if ID exists
    bool idExists(int id)
    {
        Task *temp = head;
        while (temp != NULL)
        {
            if (temp->taskID == id)
                return true;
            temp = temp->next;
        }
        return false;
    }

    // Move node to history instead of deleting
    void moveToHistory(Task *node)
    {
        node->next = historyHead; // Add to front of history (Stack behavior)
        historyHead = node;
    }

    void insertTask(int id, string desc)
    {
        // Checking for duplicate IDs first
        if (idExists(id))
        {
            cout << "Error: Task with ID " << id << " already exists! Try a different ID.\n";
            return;
        }

        Task *newTask = new Task;
        newTask->taskID = id;
        newTask->description = desc;
        newTask->status = "pending";
        newTask->next = NULL;

        // If list is empty, new task becomes head
        if (head == NULL)
        {
            head = newTask;
            cout << "Task added successfully.\n";
            return;
        }

        // Traverse to the end using temp
        Task *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newTask;
        cout << "Task added successfully.\n";
    }

    // Mark a task as completed
    void markCompleted(int id)
    {
        Task *temp = head;
        while (temp != NULL)
        {
            if (temp->taskID == id)
            {
                temp->status = "completed";
                cout << "Task ID " << id << " marked as completed.\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Task ID not found.\n";
    }

    // function to delete a completed task.
    //  (This function deletes ALL tasks that have status 'completed')
    void deleteCompletedTasks()
    {
        if (head == NULL)
        {
            cout << "No tasks to delete.\n";
            return;
        }

        bool deletedAny = false;
        Task *temp = head;

        // 1. Handle deletion at the Head
        while (temp != NULL && temp->status == "completed")
        {
            Task *toDelete = temp;
            head = temp->next; // Move head to the next node
            temp = head;       // Update temp to new head

            cout << "Deleted completed task ID: " << toDelete->taskID << endl;
            moveToHistory(toDelete);
            deletedAny = true;
        }

        // 2. Handle deletion in the Body (rest of the list)
        // We reuse 'temp' which is currently at the new head
        while (temp != NULL && temp->next != NULL)
        {
            if (temp->next->status == "completed")
            {
                Task *toDelete = temp->next;
                temp->next = temp->next->next;

                cout << "Deleted completed task ID: " << toDelete->taskID << endl;
                moveToHistory(toDelete);
                deletedAny = true;
            }
            else
            {
                temp = temp->next; // Move to next node only if we didn't delete anything
            }
        }

        if (!deletedAny)
        {
            cout << "No completed tasks found to delete.\n";
        }
    }

    void deleteTaskByID(int id)
    {
        if (head == NULL)
        {
            cout << "List is empty.\n";
            return;
        }

        Task *temp = head;

        // Case 1: Deleting the Head node
        if (temp->taskID == id)
        {
            head = temp->next;
            moveToHistory(temp);
            cout << "Task " << id << " deleted.\n";
            return;
        }

        // Case 2: Deleting from Body
        while (temp->next != NULL)
        {
            if (temp->next->taskID == id)
            {
                Task *toDelete = temp->next;
                temp->next = toDelete->next;
                moveToHistory(toDelete);
                cout << "Task " << id << " deleted.\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Task ID not found.\n";
    }

    // function to display the details of all the tasks.
    void displayTasks()
    {
        if (head == NULL)
        {
            cout << "No Tasks available.\n";
            return;
        }

        cout << "\n--- Task List ---\n";
        Task *temp = head;
        while (temp != NULL)
        {
            cout << "ID: " << temp->taskID
                 << "\t Status: " << temp->status
                 << "\t Desc: " << temp->description << endl;
            temp = temp->next;
        }
        cout << "================================" << endl;
    }

    // Display History (Deleted Tasks)
     void displayHistory()
    {
        if (historyHead == NULL)
        {
            cout << "History is empty.\n";
            return;
        }
        cout << "\n--- Deleted History ---\n";
        Task *temp = historyHead;
        while (temp != NULL)
        {
            cout << "ID: " << temp->taskID << "\t (Deleted) \t " << temp->description << endl;
            temp = temp->next;
        }
        cout << "-----------------------\n";
    }
};

int main()
{
    TaskManager m1;
    int choice, id;
    string desc;

    while (true)
    {
        cout << "\n===== CURAJ Task Manager =====";
        cout << "\n 1. Add Task";
        cout << "\n 2. Mark Task as Completed";
        cout << "\n 3. Delete Completed Tasks";
        cout << "\n 4. Delete Task by ID";
        cout << "\n 5. Display Tasks";
        cout << "\n 6. Display Deleted History";
        cout << "\n 7. Exit";
        cout << "\n Enter your Choice: ";

        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Task ID: ";
            cin >> id;
            cout << "Enter Description: ";
            cin.ignore();
            getline(cin, desc);
            m1.insertTask(id, desc);
            break;

        case 2:
            cout << "Enter Task ID: ";
            cin >> id;
            m1.markCompleted(id);
            break;

        case 3:
            m1.deleteCompletedTasks();
            break;

        case 4:
            cout << "Enter Task ID: ";
            cin >> id;
            m1.deleteTaskByID(id);
            break;

        case 5:
            m1.displayTasks();
            break;

        case 6:
            m1.displayHistory();
            return 0;

        case 7:
            cout << "Exiting Program...\n";
            return 0;

        default:
            cout << "Invalid Choice! Try again.\n";
        }
    }
    return 0;
}