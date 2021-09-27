# Introduction to the Development Environment

This lab is in a Jupyter notebook (`Lab.ipynb`).  To run it'll you'll need to 

1.  Get access to Docker (either through campus or on your own machine)
2.  Check out the lab.

This document describe how to do those two things.  Then, you'll be able to
open the Jupyter notebook and proceed with lab itself.

# Software You Will Need

**Note** Safari and Internet Explorer are not currently supported.  This will
probably be fixed by the next lab, but for this lab you should use Chrome
(first choice, most tested) or Firefox.  Edge Seems to be ok.

All your work for the class will be done in a docker container, and most of it
will be done in a Jupyter Notebook inside that docker container.

Docker containers are self-contained Linux-based workspaces.  Using docker
ensures that your code runs in a consistent environment for you and the
autograder/course staff.

Jupyter Notebook is an interactive computing enviroment for gathering and
displaying data (among other things).

The content for each lab will be distributed via github classroom.

So, to do the course, you need:

1. You'll need access to a computer running docker and jupyter notebook. 
2. Tha lab from github classroom.  Find the link on the course home page: https://github.com/CSE141pp/Home/.

There are two options for getting access to docker/jupyter notebook:  

1.  Via ssh and UCSD's DSMLP server farm. (A little cumbersome, but well-tested)
2.  Via the DSMLP docker hub. (A new, supposedly better option)


## Option 1:  SSH and DSLMP

### Get on the VPN

To use the campus servers, you'll also need to be on the [campus
VPN](https://blink.ucsd.edu/technology/network/connections/off-campus/VPN/).  

I know it's not great.  We have tried to find a way around it and there is nothing we can do.

**Note** It can sometimes takes several minutes to connect to the VPN.  Sorry about that :-(

**Note** Be sure connect to the VPN before you start login to
  `dsmlp-login`.  You can ssh into the `dsmlp-login` without the VPN,
  but some things don't work after that point if you are not on the
  VPN.

### Use dsmlp-login.ucsd.edu

This is the official way to use the class infrastructure.  If you have trouble
getting any of the other options to work, use this.

Login to `dsmlp-login.ucsd.edu` (our primary student Linux SSH server) using you normal student login.

Run the command `launch-142` to connect to a remote Docker container running the development environment image.

Here's a transcript of the login process for user `oweng`:

```
Attempting to create job ('pod') with 1 CPU cores, 4 GB RAM, and 0 GPU units.
   (Adjust command line options, or edit "/software/common64/dsmlp/bin/launch-142" to change this configuration.)
pod/oweng-7833 created
Fri Sep 24 13:11:21 PDT 2021 starting up - pod status: Pending ; Successfully assigned oweng/oweng-7833 to its-dsmlp-n25.ucsd.edu
Fri Sep 24 13:11:27 PDT 2021 pod is running with IP: 10.35.193.139 on node: its-dsmlp-n25.ucsd.edu
ucsdnvsl/cse141pp:latest is now active.

Please connect to: http://dsmlp-login.ucsd.edu:12750/?token=4afe375aeba7237123dad2497caad9ab975c2e21057e8a009545648a9babd043

Connected to oweng-7833; type 'exit' to terminate pod/processes and close Jupyter notebooks.
/course/CSE141pp-Config ~
cat: /course/CSE141pp-Config/secrets/packet_auth_token: No such file or directory
sysctl: setting key "kernel.perf_event_paranoid": Read-only file system
Welcome to the archlab development environment!
STUDENT_MODE enabled
THIS_DOCKER_IMAGE=ucsdnvsl/cse141pp:sp21.188
IN_DEPLOYMENT=DEPLOYED
CLOUD_MODE=CLOUD
~
/course/CSE141pp-Config ~
cat: /course/CSE141pp-Config/secrets/packet_auth_token: No such file or directory
sysctl: setting key "kernel.perf_event_paranoid": Read-only file system
Welcome to the archlab development environment!
STUDENT_MODE enabled
THIS_DOCKER_IMAGE=ucsdnvsl/cse141pp:sp21.188
IN_DEPLOYMENT=DEPLOYED
CLOUD_MODE=CLOUD
~
$

```

To make sure everything is working, you can run `cse142 --help`.  You should get something like this:

```
Usage: cse142 [OPTIONS] COMMAND [ARGS]...

Options:
  --server URL        Base url for the HTTP interface to the cluster.
  --http / --no-http  Use HTTP or connect directly
  -v, --verbose       Be Verbose
  -d, --debug         Enable debugging
  --json              Output results in json
  --trace             Drop into the debugger immediately
  --pdb               Invoke the debugger on uncaught exception.
  -n, --dry-run       Don't do anything, just say what would be done.
  --job-type TEXT     class name of job type to use
  --help              Show this message and exit.

Commands:
  cluster
  dev      Run a docker image configured for use with cse142L.
  job
  lab
  login
  logout
  user
```

You can then clone your repo in the directory that you land in and work on it. 

Your files inside the `launch-142` environment are stored in this system:
https://datahub.ucsd.edu/hub/login.

### Connecting to Jupyter Notebook

If you are running on DSMLP, there is a url that appears early in the login
that will tell you where to connect.  In the example above, it's this line:

```
Please connect to: http://dsmlp-login.ucsd.edu:1989/?token=80fb1310d723d124880cc21035afed53d675d7b776aef57d0ebed2c80b33d8
```

If it has scrolled away you can get it back with 

```
echo $LAUNCH_PROXY_URL
```

Copy and paste that url into a browser or click on it and then navigate to the directory where you cloned out the lab.

If you get

```
This site can’t be reached
dsmlp-login.ucsd.edu refused to connect.
```

That's because you aren't on the VPN.  You may need to log all the way out of dslmp and back in after you connected to the VPN.


## Option 2: UCSD Datahub

You can stick with a web-only interface by using UCSD Datahub.  This part of
the same system as DSMLP and your directory is shared, so you can pretty easily
switch between Option 1 and Option 2.

The first step is to visit

https://datahub.ucsd.edu/ 

One of two things will happen:

1. You'll find yourself at a nice home page and you can click the big golden "Log In" button. 

2. If you've used the system before/recently it might drop you directly into a jupyter notebook file browser.

If you it's #2, you will need to click "Control Panel" (upper right) and then click the big red "Stop My Server" button, if it's there.  If it's not, that's fine.  Then click "Logout" (upper right) to get back to the homepage and the big golden button.

Now, click the big golden button and login with your `@ucsd.edu` email address.
You'll be presented with a list of Course Environments to choose from.  Select
the one for `CSE 142L [FA21]`.

After a progress bar, you'll end up at the Jupyter Notebook file browser.
Looking at an empty directory (unless you've used the Datahub before, in which
case your old files will be there).  In any case, you don't have a lab to do
yet.

To do that you'll need a shell.  You can get one by clicking "New" (upper
right) and then "terminal", which will open up a terminal in your web browser.

You can now proceed with the instructions below for cloning the lab repo.  Once
you complete them, you can return to the Jupyter Notebook file browser and open
your lab notebook.

### Important Note

Datahub tries to keep your session alive, so if you navigate away and then come
back later, your notebook will still be there and it will initially seem to be
working, but then commands in the notebook will start failing and complaining
about "stale file handles". If this happens, you need to go to "control panel"
and stop your server and then restart it.

## Cloning the Lab Repo

First, accept the assignement on Github Classroom.  It's available via the 142L
[home page](https://github.com/CSE141pp/Home/).

This will set you up with a copy of the starter repository.


You'll need to open a terminal from data hub.  From the file browser, lect "new->terminal" from the menu in the upper right.
At the resulting Linux prompt, you can `git clone` the repo locally.

**Note**: Be sure to use the `ssh` method to checkout your repo rather than `http`. 

![clone with ssh](images/clone-with-ssh.png)


**Note**: Be sure to use the **`ssh`** method to checkout your repo rather than `http`.  Authentication over ssh is much simpler and it's what our tools assume.  If you try to use HTTP, you'll get something like:


```
sjswanson@dsmlp-jupyter-sjswanson:~/tt$ git clone http://github.com/NVSL/CSE141pp-Lab-Common.git
Cloning into 'CSE141pp-Lab-Common'...
Username for 'https://github.com': stevenjswanson
Password for 'https://stevenjswanson@github.com':
remote: Support for password authentication was removed on August 13, 2021. Please use a personal access token instead.
remote: Please see https://github.blog/2020-12-15-token-authentication-requirements-for-git-operations/ for more information.
fatal: Authentication failed for 'https://github.com/NVSL/CSE141pp-Lab-Common.git/'
```

You may need to create an ssh key and add it to your github account.  You can create the key with (in your datahub terminal):

```
ssh-keygen
```

and accept the defaults.  I recommend no password.

Then view your new public key:

```
cat ~/.ssh/id_rsa.pub
```

Then follow these instructions:

https://docs.github.com/en/github/authenticating-to-github/connecting-to-github-with-ssh/adding-a-new-ssh-key-to-your-github-account



## Open the Notebook

Switch to the tab with file browser and navigate to the directory you just cloned.   Click on `Lab.ipynb` to open the lab and get to work!
