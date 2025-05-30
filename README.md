# 🌳 Algorithms and Data Structures – Tree-Based Q&A System

Welcome to **Algorithms and Data Structures**, a C++ project implementing a tree structure designed to manage and organize questions and answers in a hierarchical format. This structure is ideal for building knowledge bases, support systems, or forum-like environments.

---

## 📂 Project Structure

| File / Folder           | Description                      |
|------------------------|---------------------------------|
| `.idea/`               | Project-specific settings (IDE generated) |
| `cmake-build-debug/`   | Build directory (IDE generated) |
| `CMakeLists.txt`       | Build configuration for CMake   |
| `README.md`            | Project documentation (this file) |
| `main.cpp`             | Program entry point             |
| `cvor.cpp` / `cvor.h`  | Node (vertex) implementation    |
| `stabla.cpp` / `stabla.h` | Tree implementation            |

---

## 📌 Project Overview

This program defines a **Tree** data structure that allows users to create and manipulate a hierarchy of questions and answers. Each node in the tree represents either a **question** or an **answer**.

---

## 🚀 Features

The application offers the following functionalities:

- 🌱 Create a new tree structure  
- ➕ Add a new question  
- ➕ Add an answer to a question or another answer  
- 🔍 Search for questions  
- 🔎 Preorder search through answers  
- ⭐ Increase the rating of an answer  
- 🔢 Sort answers by rating  
- 🖨️ Print all questions  
- 🖨️ Print the entire tree (in readable format)  
- ❌ Delete a question or answer along with all its descendants  
- 🏆 Find the question with the most descendants  
- 🚪 Exit the program  

Each option provides a unique way to explore and manage the question-answer hierarchy.

---

## 🛠️ Installation & Usage

Follow these steps to get started:

```bash
# 1. Clone the repository:
git clone <repository-url>

# 2. Compile the program using CMake or any C++ compiler:
mkdir build && cd build
cmake ..
make

# 3. Run the executable:
./tree-qa


