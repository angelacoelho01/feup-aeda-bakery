
#ifndef FEUP_AEDA_PROJECT_PERSON_EXCEPTIONS_H
#define FEUP_AEDA_PROJECT_PERSON_EXCEPTIONS_H

#include <utility>
#include <stdexcept>

#include "model/person/worker/worker.h"

/**
 * Class relative to the exception of a nonexistent person.
 */
class PersonDoesNotExist: public std::logic_error{
public:
    /**
     * Creates a new PersonDoesNotExist exception object.
     *
     * @param name the name
     * @param taxID the taxpayer identification number
     */
    PersonDoesNotExist(const std::string& name, unsigned long taxID);

    /**
     * Creates a new PersonDoesNotExist exception object.
     *
     * @param taxID the taxpayer identification number
     */
    explicit PersonDoesNotExist(unsigned long taxID);
};

/**
 * Class relative to the exception of an invalid person position on some list.
 */
class InvalidPersonPosition : public std::invalid_argument{
public:
    /**
     * Creates a new InvalidPersonPosition exception object.
     *
     * @param position the position
     * @param size the persons list size
     */
    InvalidPersonPosition(unsigned long position, unsigned long size);
};

/**
 * Class relative to the exception of an invalid credential.
 */
class InvalidCredential : public std::invalid_argument {
public:

    /**
     * Create new InvalidCredential exception object.
     */
    explicit InvalidCredential();
};

/**
 * To be thrown when all workers have reached their maximum delivery capacity.
 */
class AllWorkersAreBusy : public std::logic_error {
public:
    /**
     * Create new AllWorkersAreBusy exception object.
     */
    explicit AllWorkersAreBusy();
};


#endif //FEUP_AEDA_PROJECT_PERSON_EXCEPTIONS_H
