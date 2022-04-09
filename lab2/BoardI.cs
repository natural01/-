using System.Collections.Generic;

namespace ScrumBoard.Body
{
    public interface BoardI
    {
        public void Delete_task(string taskTitle);
        public void Rename_task(string taskTitle, string newTitle);
        public void Change_task_description(string taskTitle, string newDescription);
        public void Add_task_to_column(TaskId task, string columnTitle = null);
        public void Change_task_priority(string taskTitle, Task_priority newPriority);
        public void Move_task(string taskTitle);
        public string Title { get; }
        public ColumnI Find_column_by_title(string title);
        public void Add_column(ColumnI column);
        public void Rename_column(string columnTitle, string newTitle);
        public IReadOnlyCollection<ColumnI> Find_columns();
    }
}