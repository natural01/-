using System.Collections.Generic;

namespace ScrumBoard.Body
{
    public class Column : ColumnI
    {
        public string Title { get; set; }

        public Column(string title)
        {
            Title = title;
            _tasks = new();
        }
        public TaskId Find_task_by_title(string title)
        {
            return _tasks.Find(task => task.Title == title);
        }

        public void Delete_task_by_title(string title)
        {
            _tasks.RemoveAll(task => task.Title == title);
        }

        public void Add_task(TaskId task)
        {
            _tasks.Add(task);
        }

        public IReadOnlyCollection<TaskId> Find_tasks()
        {
            return _tasks;
        }

        private List<TaskId> _tasks;
    }
}