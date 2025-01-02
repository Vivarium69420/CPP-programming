<!-- markdownlint-disable MD013 -->

# Requirement

- A production unit includes officers who can be workers, engineers, or staff. Each officer needs to manage the following data: full name, age, gender (male, female, other), and address.

  - Workers have an additional attribute: level (ranging from 1 to 10).
  - Engineers have an additional attribute: specialization (field of training).
  - Staff have an additional attribute: task (specific job).

- Requirement 1: Build the classes Worker, Engineer, and Staff, which inherit from the base class Officer.
- Requirement 2: Create a class OfficerManager that implements the following functionalities:
  - Add a new officer.
  - Search for officers by their full name.
  - Display information about the list of officers.
  - Exit the program.
