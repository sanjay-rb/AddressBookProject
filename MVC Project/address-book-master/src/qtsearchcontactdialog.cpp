#include "contact.h"
#include "qtcontactform.h"
#include "qtsearchcontactdialog.h"
#include <QDialog>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>


QtSearchContactDialog::QtSearchContactDialog(Contact &c,
                                        QWidget *parent,
                                        Qt::WindowFlags f) :
                                        QDialog(parent, f),
                                        contactForm(new QtContactForm()),
                                        serachelement(c)
{
    QLineEdit *find_F_name = new QLineEdit();
    QLineEdit *find_L_name = new QLineEdit();
    QFormLayout *search_form = new QFormLayout();
    search_form->addRow("First Name", find_F_name);
    search_form->addRow("Last Name", find_L_name);
    QVBoxLayout *mainContainer = new QVBoxLayout();
    mainContainer->addLayout(search_form);

    QHBoxLayout *buttonContainer = new QHBoxLayout();
    QPushButton *addButton = new QPushButton("Add");
    QPushButton *cancelButton = new QPushButton("Cancel");

    buttonContainer->addWidget(addButton);
    buttonContainer->addWidget(cancelButton);
    mainContainer->addLayout(buttonContainer);

    connect(addButton, SIGNAL(clicked()), this, SLOT(accept()));
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(reject()));

    setLayout(mainContainer);
    setWindowTitle("Find");
}

void QtSearchContactDialog::accept(){
    serachelement.firstName = contactForm->firstNameField->text().toStdString();
    serachelement.lastName = contactForm->lastNameField->text().toStdString();
    /*serachelement.address = contactForm->addressField->text().toStdString();
    serachelement.phoneNumber = contactForm->phoneNumberField->text().toStdString();
    serachelement.email = contactForm->emailField->text().toStdString();
    serachelement.city = contactForm->cityField->text().toStdString();
    serachelement.age = contactForm->ageField->text().toStdString();*/


    QDialog::accept();
}


