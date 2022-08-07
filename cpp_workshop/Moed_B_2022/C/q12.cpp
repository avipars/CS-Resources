#include <iostream>

class Account
{
protected:
    int number = 0;
    float interest = 0;
    float balance = 0;

private:
    virtual bool mayWithdraw(float amount) const = 0;

public:
    Account(int n, float b);
    void withdraw(float amount);
    virtual void update(); // update balance and interest
};

Account::Account(int n, float b) : number(n), balance(b) {}

void Account::withdraw(float amount)
{
    if (mayWithdraw(amount))
    {
        balance -= amount;
    }
}

void Account::update()
{
    if (balance > 0)
    {
        balance += balance * interest;
    }
}

class Savings : public Account
{
private:
    bool mayWithdraw(float amount) const override;

public:
    Savings(int n, float b);
};

Savings::Savings(int n, float b) : Account(n, b)
{
    // set interest
    interest = 0.05;
}

bool Savings::mayWithdraw(float amount) const
{
    if (balance >= amount)
    {
        return true;
    }
    return false;
}

class Credit : public Account
{
protected:
    float overdraft = 0;

private:
    bool mayWithdraw(float amount) const override;

public:
    Credit(int n, float b);
    void update() override;
};

Credit::Credit(int n, float b) : Account(n, b)
{
    // set interest
    interest = 0.01;
    overdraft = 0;
}

bool Credit::mayWithdraw(float amount) const
{
    if (balance + overdraft >= amount)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Credit::update()
{
    if (balance + overdraft > 0)
    {
        balance += balance * interest;
    }
    else
    {
        balance -= 25;
    }
}