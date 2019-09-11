# Git -- the basics

> Git is a powerfull tool used by many open-source projects created by Linus Torval himself.

Git allow you to have a repository both localy and online. It's an asynchrone tool that allow you to work localy, online, share/show your work, make `branch` (alternative version) keep an history of modification, generate web pages and more. It take time to understand and 'master' but it really worth the shot!

**Let's dive!**

## Start a repository

To start a repository you have two ways to do it. Weither you have a local file that you want to synchronized online or the oposite.

You have a good explanation on how to start on the page of K. Broman --> [Start a new git repository](https://kbroman.org/github_tutorial/pages/init.html)

## Liste of commands :

* **Synchronized an online repository :**
``` bash
git clone <link of the repository>
```
* **get the online history :**
``` bash
git fetch
```
* **get the online files :**
``` bash
git pull <remote> <branch>
```
exemple : `git pull origin master`

* **push files from local to online :**
``` bash
git add .
git commit -am'commit message'
git push <remote> <branch>
```
exemple : `git push origin master`
* **add a new remote :**
> To synchronize with another repository, could be on Github and Gitlab at the same time
``` bash
git remote add <name of the new remote> <link of the repository>
```
* **list all the available remote**
``` bash
git remote -v
```
* ****
