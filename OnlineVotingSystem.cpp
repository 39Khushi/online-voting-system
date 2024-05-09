#include <iostream>
#include <vector>
#include <map>
#include <string>

class VotingSystem {
private:
    std::map<std::string, int> votes;

public:
    void addCandidate(const std::string& candidate) {
        if (votes.find(candidate) == votes.end()) {
            votes[candidate] = 0;
        }
    }

    void castVote(const std::string& candidate) {
        if (votes.find(candidate) != votes.end()) {
            votes[candidate]++;
        } else {
            std::cout << "Candidate not found.\n";
        }
    }

    void showResults() const {
        std::cout << "\nVoting Results:\n";
        for (const auto& pair : votes) {
            std::cout << pair.first << ": " << pair.second << " votes\n";
        }
    }
};

int main() {
    VotingSystem system;

    // Add candidates
    system.addCandidate("Alice");
    system.addCandidate("Bob");
    system.addCandidate("Charlie");

    bool voting = true;
    std::string vote;

    while (voting) {
        std::cout << "Enter your vote (type 'exit' to finish): ";
        std::cin >> vote;

        if (vote == "exit") {
            voting = false;
        } else {
            system.castVote(vote);
        }
    }

    system.showResults();

    return 0;
}
