
# Student Addmission System

The `Student Management System` is a console application designed to streamline the management of student enrollment, faculty assignment, exam scheduling, and admit card generation for addmission examinations. 

It provides functionalities for:

- **Student Registration**: Students can register by providing their details like name, father's name, CNIC (Computerized National Identity Card number, if applicable), and desired faculty.
- **Faculty Selection**: Students can choose their preferred faculty (e.g., Software Engineering, Computer Science) upon registration.
- **Faculty Assignment**: The system can automatically assign students to faculties based on faculty availability and workload.
- **Exam Scheduling8**: The system can manage exam schedules, considering factors like faculty availability and student preferences. (This functionality might not be implemented in the current version.)
- **Admit Card Generation**: Students can authenticate themselves using their login credentials (name and password) to download their admit cards containing exam details like name, faculty, CNIC (if entered), timing, and allocated room number.

**Important Notes**:
- The code utilizes functions like `system("cls")` for clearing the screen and color manipulation (`red()`, `green()`, `reset()`) to enhance the user experience.
 - Error handling is included to address invalid user choices.

**Further Improvements**:
- The project is under development, with functions yet to be implemented (e.g., `addTeacher()` or `createClass()` for adding faculty and creating classes rather than just using pre defined data).
- For a more robust and user-friendly experience, we consider using a higher-level language like Python with libraries for GUI development (e.g., `Tkinter`, `PyQt`).
- Security improvements could be implemented by storing passwords securely (e.g., `hashing` with `salting`).
- `Error handling` could be enhanced to provide more informative messages to users.

> Dec 2023 1st Semester Programming Fundamentals Project
## Authors

- [@sadamumer3](https://www.github.com/sadamumer3)

