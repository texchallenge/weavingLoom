# Git installation

*The main core of Github is Git !*

### Installation
First of all, you have to **install git environment** on your computer.

You can follow this tutorial well explained for each OS in the git documentation --> [here](https://git-scm.com/book/en/v2/Getting-Started-Installing-Git)

Once it's done you should be able to prompt some git command line in a bash.

### Create an accoumpt on Github

clicking `Sign Up`! and then follow the step.

> To be able to use the command line properly you have to identify yourself and your computer so github will reconized you each time you do something.

### setting up your bash / terminal

> In your terminal start by typing and validating this two lines. Be sure to put the same user name and user email than you previously  used to subscribe on git.

``` bash
$ git config --global user.name "John Doe"
$ git config --global user.email johndoe@example.com
```

### create an SSH key

> The ssh protocole is an identification protocole pretty well secured.

To be able to push / pull some content on Github, the most common way is to settle an SSH keygen so you wan't have to prompt and identify yourself each time than you want to do something on the repository.

You can use this comand line :
``` bash
$ ssh-keygen
```
It will activate an ssh keygen generator.
Be aware that this will create a folder named `.ssh` in your user directory. In this folder you should have two files :

* id_rsa --> private key
* id_rsa.pub --> public key

 To use it with git, open the `id_rsa.pub` file in a *text editor*,

Then follow this simple steps : [Adding a new SSH key to your GitHub account](https://help.github.com/en/articles/adding-a-new-ssh-key-to-your-github-account)

That's it for Git installation. Let's go to the basics !
