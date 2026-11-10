# Instructions

Update this document where indicated [look for the brackets!]. Replace text inside the brackets with your own information. For example: Course Name should be the name of this course, and not the generic words "Course Name".

<br>

## [ COS119 ]

- **[ Tyler Becker ]**
- **[ Nov 1 2026]**

This paper addresses some of the topic matter covered in research and activity this week. Be sure to include reference links below to the research and information you used to complete this assignment.

## Topic: Terminal

Professional developers use Terminal daily. It's essential to understand some fundamental commands to use the application.

Update the information below to demonstrate your knowledge on this topic.

**1. Using Terminal, there are essential commands to know.**

List the correct Terminal commands to do the actions listed below. Replace **CMD** with the correct command sequence. You can keep or enhance the brief description.

**The last bullet provides an example**.

- [ Clear]: Clear the Screen
- [ pwd]: Print the "Working Directory"
- [ ls ]: List files and folders
- [ ls -a ]: List files and folders, including invisible files
- [ ls -lah ]: List all files and folders, in human readable form
- [ cd folder_name]: Change directory
- [ cd /]: Change directory, go to root directory
- [ cd ~ ]: Change directory and go to user home directory
- [ cd .. ]: Change directory, go up one folder level
- [ cd ../.. ]: Change directory, go up two folder levels
- [ cd ~/Desktop ]: Change directory to my desktop!

**2. Using Terminal...**

**Folder Drop:** Try typing "cd" followed by a space, and then drag a folder into terminal and press return. Test this out and describe your results below.

[ When typing in cd into the terminal and dropping in a folder. We see the folders full path. ]

## Topic: Version Control & Git

Version control, also known as revision control, records changes to a file or set of files over time so that you can recall specific versions later. In this class, we are learning Git. Update the information below where indicated.

**1. There are three types of version control.**

[ Local which stores file versions in a database on your own computer. Centralized which stores files in one location that everyone shares. Distributed gives every user a copy to work offline with. ]

**2. Using Terminal, there are also essential Git commands to know.**

List the correct Git commands to do the actions listed below in Terminal. Replace CMD with the correct command and keep or enhance the brief description.

- [ git clone<repository-url]: Clone a repository
- [ git config -- global user.name "Your Name"]: Set-up a global user name
- [ git config --global user.email "you@example.com]: Set-up a global email address (to match my GitHub account email)
- [ git status]: Shows the current state of your directory and staging area
- [ git add]: Add modified files to the next commit
- [ git commit -m]: Make a commit with a new message
- [ git log]: Show my commit history
- [ git --help]: Show Git's help screen

**3. Connecting to GitHub using Terminal.**
HTTPS is the the correct way to connect to GitHub in this course. Describe how you connect to GitHub from Terminal using this protocol. What steps do you take?

[ Open the repo on Github click code select https and copy. Open terminal and navigate to where you want it saved. Type in git clone followed by the https link and press return.  ]

**4. Using .gitignore and Why it's Important**  
Most repositories contain a .gitignore file.

- What is the purpose of this file?
  <br>
  [It tells git essentially which files to ignore]

- What is the "**.DS_Store**" file and why would you want to ignore it?
  <br>
  [It is a hidden macOS, and it is unrelated to the projects code and can clutter up the repo.]

- What other file or folder would you want to add to a .gitignore file and why?
  <br>
  [node_modules because it contains downloaded dependencies that can be reinstalled if needed.]

<br>

# Reference Links

Replace the example references below with your own links and recommended resources. It is acceptable to provide multiple links for a single topic and to use material provided to you in this class. You are encouraged to link to your own independent research as well.

The GitHub documentation and the _Pro Git_ book were the most helpful resources because they explained both the commands and the reasons behind using them. The version control overview helped me understand how Git differs from centralized systems. GitHub’s guides also clarified how to clone a repository using HTTPS and keep unnecessary files out with .gitignore.

**Terminal Commands**  
https://support.apple.com/guide/terminal/welcome/mac

**Three Types of Version Control**  
https://git-scm.com/book/en/v2/Getting-Started-About-Version-Control.html

**Git Commands**  
https://docs.github.com/en/get-started/using-git/about-git

**Connecting to GitHub using Terminal**  
https://docs.github.com/en/repositories/creating-and-managing-repositories/cloning-a-repository
https://docs.github.com/en/authentication/keeping-your-account-and-data-secure/about-authentication-to-github

**Using .gitignore and Why it's Important**  
https://docs.github.com/en/get-started/git-basics/ignoring-files
https://git-scm.com/docs/gitignore
