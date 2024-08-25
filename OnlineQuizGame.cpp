#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

// Structure to represent a question
struct Question {
    string question;
    vector<string> options;
    int correctAnswerIndex;
};

// Structure to represent a user
struct User {
    string username;
    int score;
};

// Function to display all available options for a question
void displayOptions(const vector<string>& options) {
    for (int i = 0; i < options.size(); ++i) {
        cout << i + 1 << ". " << options[i] << endl;
    }
}

// Function to ask a question to the user
int askQuestion(const Question& question) {
    cout << question.question << endl;
    displayOptions(question.options);
    int answer;
    cout << "Your answer (1-" << question.options.size() << "): ";
    cin >> answer;
    return answer - 1;  // Convert to zero-based index
}

// Function to display all questions and answers at the end of the quiz
void displayAnswers(const vector<Question>& questions) {
    cout << "\nCorrect Answers:\n";
    for (int i = 0; i < questions.size(); ++i) {
        cout << "Q" << i + 1 << ": " << questions[i].question << endl;
        cout << "Correct Answer: " << questions[i].options[questions[i].correctAnswerIndex] << "\n\n";
    }
}

// Main quiz game function
void quizGame() {
    // List of questions
    vector<Question> questions = {
        {"What is the capital of France?", {"Paris", "London", "Rome", "Berlin"}, 0},
        {"Who wrote 'Hamlet'?", {"Charles Dickens", "J.K. Rowling", "William Shakespeare", "George Orwell"}, 2},
        {"What is the largest planet in our Solar System?", {"Earth", "Mars", "Jupiter", "Saturn"}, 2},
        {"What year did the World War II end?", {"1942", "1945", "1946", "1950"}, 1}
    };

    // Register user
    User user;
    cout << "Welcome to the Quiz Game!" << endl;
    cout << "Please enter your username: ";
    cin >> user.username;
    user.score = 0;

    // Ask each question
    for (const auto& question : questions) {
        int userAnswer = askQuestion(question);
        if (userAnswer == question.correctAnswerIndex) {
            cout << "Correct!\n";
            user.score++;
        } else {
            cout << "Wrong! The correct answer was: " << question.options[question.correctAnswerIndex] << "\n";
        }
        cout << "----------------------------------\n";
    }

    // Display user's score
    cout << user.username << ", your total score is: " << user.score << " out of " << questions.size() << endl;

    // Display correct answers at the end
    displayAnswers(questions);
}

// Main function
int main() {
    quizGame();
    return 0;
}
