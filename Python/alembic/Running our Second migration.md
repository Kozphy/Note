# Running our Second migration
###### tags: `database learn`

Let’s do another one so we have some things to play with. We again create a revision file:
```cmd
alembic revision -m "Add a column"
```

Let’s edit this file and add a new column to the `account` table:
```python=
"""Add a column

Revision ID: ae1027a6acf
Revises: 1975ea83b712
Create Date: 2011-11-08 12:37:36.714947

"""

# revision identifiers, used by Alembic.
revision = 'ae1027a6acf'
down_revision = '1975ea83b712'

from alembic import op
import sqlalchemy as sa

def upgrade():
    op.add_column('account', sa.Column('last_transaction_date', sa.DateTime))

def downgrade():
    op.drop_column('account', 'last_transaction_date')
```

Running again to `head`:
```python=
$ alembic upgrade head
```

We’ve now added the `last_transaction_date` column to the database.

