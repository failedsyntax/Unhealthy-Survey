#include <iostream>
#include <cmath>
#include <cstring>
#include <iomanip>
using namespace std;

class Inputs {
    float finalNumber = 0.0;

    public:
        string Questions[5][2] = { // Multi-dimensional array with question, response from user
            {"Do you like chocolate?", "N/A"},
            {"Do you like chips?", "N/A"},
            {"Do you like soda?", "N/A"},
            {"Do you like candy?", "N/A"},
            {"Do you like to sleep?", "N/A"}
        };

        void modifyQuestionResponse(string Question, string Response) {
            for (int qIndex = 0; qIndex < 5; qIndex++) { // Loop through questions
                string indexedQuestion = Questions[qIndex][0];
                if (indexedQuestion.compare(Question) == 0) {
                    Questions[qIndex][1] = Response;
                };
            };
        };

        string percentageToComment(float Percent) {
            if (Percent <= 20) {
                return "You're doing pretty good!";
            } else if (Percent > 20 && Percent <= 40) {
                return "You could do better, but not bad!";
            } else if (Percent > 40 && Percent <= 60) {
                return "Not doing the best, try harder..";
            } else if (Percent > 60 && Percent <= 80) {
                return "Really not doing great, you need to do better.";
            } else if (Percent > 80 && Percent <= 100) {
                return "Yeah, you need to get yourself together ASAP.";
            } else {
                return 0;
            };
        };

        string convertToLower(string Input) {
            string loweredInput = Input;
            for (int ind = 0; ind <= Input.length(); ind++) { // loop through the Input characters, and lower them into a new variable
                loweredInput[ind] = tolower(loweredInput[ind]);
            };  return loweredInput;
        };

        void calculateSurveyResult() {
            double NumberOfYes = 0;

            for (int i = 0; i <= 4; i++) {
                string response = Questions[i][1];
                response = convertToLower(response);
                if (response == "yes") { // if user replied with 'yes', add a number of yes responses
                    NumberOfYes += 1;
                } else {
                    NumberOfYes = NumberOfYes;
                };
            }; 
            double Average = (NumberOfYes / 5); finalNumber = (Average * 100.0);
        };

        void askQuestionare() {
            for (int i = 0; i <= 4; i++) {
                string Question = Questions[i][0];
                string Response = "";
                cout << Question << endl;
                cin >> Response; cout << "\n"; // Gain inputs from user
                modifyQuestionResponse(Question, Response);
                if (i == 4) { // If index reaches max, notify completion and reply result
                    cout << "You have completed the survey. Thank you for your time." << endl;
                    calculateSurveyResult(); cout << "Your life is "; cout << fixed << setprecision(0) << finalNumber << "%" << " unhealthy. ";
                    cout << percentageToComment(finalNumber); // Convert the 'percent' integer into a comment based on result
                };
            };
        };  
};

int main() {
	Inputs inp;
    inp.askQuestionare();
};