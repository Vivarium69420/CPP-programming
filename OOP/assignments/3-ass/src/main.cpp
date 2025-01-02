#include <iostream>

#include "../include/EnrollmentManager.h"

const int OPTION_ADD_CANDIDATE = 1;
const int OPTION_SHOW_CANDIDATE_LIST = 2;
const int OPTION_SEARCH_CANDIDATE = 3;
const int OPTION_SHOW_EXAM_GROUP = 4;
const int OPTION_EXIT = 5;

int main() {
  EnrollmentManager em;

  while (true) {
    std::cout << "--------------------------------\n";
    std::cout << OPTION_ADD_CANDIDATE << ". Add candidate\n";
    std::cout << OPTION_SHOW_CANDIDATE_LIST << ". Show candidate list\n";
    std::cout << OPTION_SEARCH_CANDIDATE << ". Search candidate\n";
    std::cout << OPTION_SHOW_EXAM_GROUP << ". Show exam group\n";
    std::cout << OPTION_EXIT << ". Exit\n";
    std::cout << "--------------------------------\n";
    std::cout << "Enter your choice: ";
    int choice = em.getValidIntInput(OPTION_ADD_CANDIDATE, OPTION_EXIT);

    switch (choice) {
      case OPTION_ADD_CANDIDATE:
        em.addCandidate();
        break;
      case OPTION_SHOW_CANDIDATE_LIST:
        em.showCandidateList();
        break;
      case OPTION_SEARCH_CANDIDATE:
        em.searchCandidate();
        break;
      case OPTION_SHOW_EXAM_GROUP:
        std::cout << "Enter exam group to display (A/B/C): ";
        char group;
        std::cin >> group;
        if (group == 'A') {
          em.displayExamGroup(group_t::A);
        } else if (group == 'B') {
          em.displayExamGroup(group_t::B);
        } else if (group == 'C') {
          em.displayExamGroup(group_t::C);
        } else {
          std::cout << "Invalid group\n";
        }
        break;
      case OPTION_EXIT:
        std::cout << "Exiting...\n";
        return 0;
      default:
        std::cout << "Invalid choice. Please try again.\n";
        break;
    }
  }

  return 0;
}