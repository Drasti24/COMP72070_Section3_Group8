CREATE DATABASE ServerDatabase;
USE ServerDatabase;


CREATE TABLE loginInformation (
    id INT PRIMARY KEY,
    username VARCHAR(255) NOT NULL,
    userPassword VARCHAR(255) NOT NULL
);


CREATE TABLE logUpOwners (
    id INT PRIMARY KEY,
    firstName VARCHAR(255) NOT NULL,
    lastName VARCHAR(255) NOT NULL,
    username VARCHAR(255) NOT NULL,
    userPassword VARCHAR(255) NOT NULL,
    businessAddress VARCHAR(255) NOT NULL,
    province VARCHAR(255) NOT NULL,
    postalCode VARCHAR(10) NOT NULL,
    businessPhone INT NOT NULL,
    licenseNumber INT NOT NULL
);


CREATE TABLE logUpAdopters (
    id INT PRIMARY KEY,
    firstName VARCHAR(255) NOT NULL,
    lastName VARCHAR(255) NOT NULL,
    username VARCHAR(255) NOT NULL,
    userPassword VARCHAR(255) NOT NULL,
    adopterBio VARCHAR(255) NOT NULL
);


CREATE TABLE petInformation (
    id INT PRIMARY KEY,
    animalType VARCHAR(255) NOT NULL,
    vaccinationStatus BOOLEAN NOT NULL,
    age INT NOT NULL
);


CREATE TABLE posts (
    id INT PRIMARY KEY,
    postTitle VARCHAR(255) NOT NULL,
    postContent VARCHAR(1000) NOT NULL,
    imageBuffer VARCHAR(10000)
);
