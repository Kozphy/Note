# install and setup
###### tags: `data analysis`
## install conda on linux/GNU
You will then have a file named something similar to Anaconda3-4.1.0-Linux-x86_64.sh.
To install it, execute this script with bash
```
$ bash Anaconda3-4.1.0-Linux-x86_64.sh
```
The Anaconda installer may ask if you wish to prepend its bin/ directory to your $PATH variable. If you have any problems after installation, you can do this yourself by modifying your .bashrc (or .zshrc, if you are using the zsh shell) with something akin to:
```
export PATH=/home/$USER/anaconda/bin:$PATH
```
After doing this you can either start a new terminal process or execute your .bashrc again with source ~/.bashrc.

## install and updating python packages
At some point while reading, you may wish to install additional Python packages that are not included in the Anaconda distribution. In general, these can be installed with the following command
```
conda install package_name
```

If this does not work, you may also be able to install the package using the pip package management tool:
```
pip install package_name
```

You can update packages by using the conda update command:
```
conda update package_name
```

pip also supports upgrades using the --upgrade flag:
```
pip install --upgrade package_name
```

## community and conferences
Outside of an internet search, the various scientific and data-related Python mailing lists are generally helpful and responsive to questions. Some to take a look at include:
- pydata: A Google Group list for questions related to Python for data analysis and pandas
- pystatsmodels: For statsmodels or pandas-related questions
- Mailing list for scikit-learn (scikit-learn@python.org) and machine learning in Python, generally
- numpy-discussion: For NumPy-related questions
- scipy-user: For general SciPy or scientific Python questions

Many conferences have financial support available for those who cannot afford admission or travel to the conference. Here are some to consider:
-  PyCon and EuroPython: The two main general Python conferences in North America and Europe, respectively
- SciPy and EuroSciPy: Scientific-computing-oriented conferences in North America and Europe, respectively
- PyData: A worldwide series of regional conferences targeted at data science and data analysis use cases
- International and regional PyCon conferences (see http://pycon.org for a complete listing)

## import conventions
The Python community has adopted a number of naming conventions for commonly used modules:
```python
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
import seaborn as sns
import statsmodels as sm
```
## Jargon
I’ll use some terms common both to programming and data science that you may not be familiar with. Thus, here are some brief definitions:
- Munge/munging/wrangling
Describes the overall process of manipulating unstructured and/or messy data into a structured or clean form. The word has snuck its way into the jargon of many modern-day data hackers. "Munge" rhymes with "grunge."
- Pseudocode
A description of an algorithm or process that takes a code-like form while likely not being actual valid source code.
- Syntactic sugar
Programming syntax that does not add new features, but makes something more convenient or easier to type.