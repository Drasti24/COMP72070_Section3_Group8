-- Table for storing login information
CREATE TABLE loginInformation (
    id INT  PRIMARY KEY,
    username VARCHAR(255) NOT NULL,
    password VARCHAR(255) NOT NULL
);

-- Table for storing sign up information
CREATE TABLE logUpOwners (
    id INT  PRIMARY KEY,
    firstName VARCHAR(255) NOT NULL,
    lastName VARCHAR(255) NOT NULL,
    username VARCHAR(255) NOT NULL,
    password VARCHAR(255) NOT NULL,
    businessAddress VARCHAR(255) NOT NULL,
    province VARCHAR(255) NOT NULL,
    postalCode VARCHAR(10) NOT NULL,
    businessPhone INT NOT NULL,
    licenseNumber INT NOT NULL
);

CREATE TABLE logUpAdopters {
    id INT PRIMARY KEY,
    firstName VARCHAR(255) NOT NULL,
    lastName VARCHAR(255) NOT NULL,
    username VARCHAR(255) NOT NULL,
    password VARCHAR(255) NOT NULL,
    adopterBio VARCHAR(255) NOT NULL
};

-- Table for storing pet information
CREATE TABLE petInformation (
    id INT  PRIMARY KEY,
    animalType VARCHAR(255) NOT NULL,
    vaccinationStatus BOOLEAN NOT NULL,
    age INT NOT NULL
);

-- Table for storing post information
CREATE TABLE posts (
    id INT  PRIMARY KEY,
    postTitle VARCHAR(255) NOT NULL,
    postContent VARCHAR(1000) NOT NULL,
    imageBuffer VARCHAR(1000)
);