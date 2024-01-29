import { useState } from "react";

export function useTask() {
    const [tasks, setTasks] = useState([]);

    function handleNewTask(event) {
    event.preventDefault();

    const input = event.target[0];

    setTasks([
        ...tasks,
        {
        id: Math.random() * 1000,
        title: input.value,
        isComplete: false,
        },
    ]);
    }

    function deleteTask(id) {
    const taskList = tasks.filter((task) => task.id !== id);

    setTasks(taskList);
    }

    function handleToggleTaskCompletion(id) {
    const taskList = tasks.map((task) => {
        if (task.id === id) {
        task.isComplete = !task.isComplete;
        }

        return task;
    });

    setTasks(taskList);
    }

    const completes = tasks.filter((task) => {
    return task.isComplete !== false;
    });

    return {
    tasks,
    handleNewTask,
    deleteTask,
    handleToggleTaskCompletion,
    completes,
    };
}