## Setup guide

The first step towards a development environment is to get a source code editor.
We recommend using [Visual Studio Code](https://code.visualstudio.com/), which
together with our [repository](https://github.com/gustavogutierrezutp/is304)
will get you up and running in no time. 

We suggest you to install the following extensions in vscode:
- [Dev
  Containers](https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.remote-containers)

## Development environment

After installing the source code editor you will need to clone the repository to
your local machine. For this you need to have [Git](https://git-scm.com/)
installed. Open vscode, go to `Open Folder` and select the folder where you
clonned the repository.

There is a `.devcontainer` folder so vscode might ask you to reopen the folder
in a container. If it does, accept. If it does not, you can open the command
palette (Ctrl+Shift+P) and type `Reopen in Container`. This will create a
development environment with all the necessary tools installed. The first time
you do this it might take a while as it will download the container image.


We recommend this approach as it will provide you with a consistent development
environment across different machines and operating systems. It is possible that
you need to have [Docker](https://www.docker.com/) installed on your machine for
this to work. If you are using Windows, you will need to have
[WSL](https://learn.microsoft.com/en-us/windows/wsl/install) installed as well.

## A "Hello World" example

Now that you have a development environment set up, let's create a simple
program to test it. Create a file named `hw.cpp` in the root of the
repository and paste the following code:

```c++
#include <iostream> 
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
```

To compile the program, open a terminal in vscode by going to `Terminal` > `New Terminal`
and run the following command:

```sh
g++ -std=c++20 -o hw hw.cpp
```

This will create an executable file named `hw`. To run the program, type:

```sh 
./hw
```
You should see the output:

```
Hello, World!
```

