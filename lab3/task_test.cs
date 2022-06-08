using Xunit;
using ScrumBoard.Body;

namespace ScrumTest
{
    public class TaskTests
    {
        private TaskId TrialTask()
        {
            return Creator.Create_task(TrialTitle, TrialDescription, TrialPriority);
        }
        private string TrialTitle = "Title";
        private string TrialDescription = "Description";
        private Task_priority TrialPriority = Task_priority.MEDIUM;

        [Fact]
        public void Create_taskToColumn()
        {

            TaskId task = TrialTask();



            Assert.Equal(TrialTitle, task.Title);
            Assert.Equal(TrialDescription, task.Description);
            Assert.Equal(TrialPriority, task.Priority);
        }

        [Fact]
        public void Rename_task_title()
        {

            TaskId task = TrialTask();
            string newTitle = "Updated";

            task.Title = newTitle;

            Assert.Equal(newTitle, task.Title);
        }

        [Fact]
        public void ChangeTask_priority()
        {

            TaskId task = TrialTask();
            Task_priority newPriority = Task_priority.HARD;

            task.Priority = newPriority;

            Assert.Equal(newPriority, task.Priority);
        }

        [Fact]
        public void RenameTaskDescription()
        {
            TaskId task = TrialTask();
            string newDescription = "Updated";

            task.Description = newDescription;

            Assert.Equal(newDescription, task.Description);
        }
    }
}
