using System.Collections.Generic;

namespace ScrumBoard.Body
{
    public interface ColumnI
    {
        public string Title { get; set; }

        public void Add_task(TaskId task);
        public void Delete_task_by_title(string title);
        public TaskId Find_task_by_title(string title);
        public IReadOnlyCollection<TaskId> Find_tasks();
    }
}