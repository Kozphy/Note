# Create a Migration Script
###### tags: `database learn`

With the environment in place we can create a new revision, using `alembic revision`:
```cmd=
alembic revision -m "create account table"
```

A new file`<revisionID>_create_account_table.py` is generated. Looking inside the file:
```python=
"""create account table

Revision ID: 1975ea83b712
Revises:
Create Date: 2011-11-08 11:40:27.089406

"""

# revision identifiers, used by Alembic.
revision = '1975ea83b712'
down_revision = None
branch_labels = None

from alembic import op
import sqlalchemy as sa

def upgrade():
    pass

def downgrade():
    pass
```

Our job here is to populate the `upgrade()` and `downgrade()` functions with directives that will apply a set of changes to our database. Typically, upgrade() is required while `downgrade()` is only needed if down-revision capability is desired.

Another thing to notice is the `down_revision` variable. This is how Alembic knows the correct order in which to apply migrations. When we create the next revision, the new file’s `down_revision` identifier would point to this one:
```python=
# revision identifiers, used by Alembic.
revision = 'ae1027a6acf'
down_revision = '1975ea83b712'
```

Every time Alembic runs an operation against the `versions/` directory, it reads all the files in, and composes a list based on how the `down_revision` identifiers link together, with the `down_revision` of None representing the first file.

We can then add some directives to our script, suppose adding a new table `account`:
```python=
def upgrade():
    op.create_table(
        'account',
        sa.Column('id', sa.Integer, primary_key=True),
        sa.Column('name', sa.String(50), nullable=False),
        sa.Column('description', sa.Unicode(200)),
    )

def downgrade():
    op.drop_table('account')
```
`create_table()` and `drop_table()` are Alembic directives. Alembic provides all the basic database migration operations via these directives, which are designed to be as simple and minimalistic as possible; there’s no reliance upon existing table metadata for most of these directives.

They draw upon a global “context” that indicates how to get at a database connection (if any; migrations can dump SQL/DDL directives to files as well) in order to invoke the command. This global context is set up, like everything else, in the `env.py` script.

