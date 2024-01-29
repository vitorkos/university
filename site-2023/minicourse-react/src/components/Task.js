import { RiDeleteBin6Line } from "react-icons/ri";

export const Task = ({ task, onDeleteTask, handleToggleTaskCompletion }) => {
    return (
    <>
        <ul
        className={`w-4/6 m-auto p-3 rounded-md bg-box mb-2 ${
            task.isComplete ? "opacity-30" : "opacity-100"
        }`}
        >
        <li className="flex justify-between items-center">
            <div className="space-x-2">
            <input
                defaultChecked={task.isComplete}
                onClick={() => handleToggleTaskCompletion(task.id)}
                type="checkbox"
            />
            <span
                className={`text-white ${
                task.isComplete ? "line-through" : "no-underline"
                }`}
            >
                {task.title}
            </span>
            </div>
            <button onClick={() => onDeleteTask(task.id)} type="button">
            <div className="hover:text-red-800 transition-colors text-gray-700">
                <RiDeleteBin6Line />
            </div>
            </button>
        </li>
        </ul>
    </>
    );
};