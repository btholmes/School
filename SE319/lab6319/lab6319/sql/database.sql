-- phpMyAdmin SQL Dump
-- version 4.4.14
-- http://www.phpmyadmin.net
--
-- Host: localhost
-- Generation Time: Nov 06, 2016 at 12:32 AM
-- Server version: 5.6.26
-- PHP Version: 5.6.12

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `Library`
--

-- --------------------------------------------------------

--å
-- Table structure for table `books`
--

CREATE TABLE IF NOT EXISTS `books` (
  `BookId` int(10) NOT NULL,
  `BookTitle` varchar(255) NOT NULL,
  `Author` varchar(255) NOT NULL,
  `Availability` tinyint(4) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `books`
--

INSERT INTO `books` (`BookId`, `BookTitle`, `Author`, `Availability`) VALUES
(1, 'Davinci', 'Davinci', 1),
(2, 'The Soul', 'Yawei', 1),
(3, 'Michael', 'MJ', 1),
(4, 'Pride and Prej.', 'Someone', 1),
(5, 'More Art', 'Artist', 1),
(6, 'Artsie', 'Art', 1),
(7, 'Inspirational', 'Bashar', 1),
(8, 'Play Like A Pro', 'Jay Z', 1),
(9, 'Hockey', 'Wayne Gretzky', 1),
(10, 'Nature', 'Mother', 1),
(11, 'Colors', 'Life', 0),
(12, 'How to Gamble', 'Gangsta', 1),
(13, 'I hate math', 'Lit', 1),
(14, 'Make Me Rich', '.....', 1);

-- --------------------------------------------------------

--
-- Table structure for table `loanHistory`
--

CREATE TABLE IF NOT EXISTS `loanHistory` (
  `userName` varchar(255) NOT NULL,
  `BookId` int(10) NOT NULL,
  `DueDate` date NOT NULL,
  `ReturnedDate` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `loanHistory`
--

INSERT INTO `loanHistory` (`userName`, `BookId`, `DueDate`, `ReturnedDate`) VALUES
('user', 5, '2016-11-20', '2016-11-05'),
('user', 10, '2016-11-20', '2016-11-05'),
('user', 11, '2016-11-20', '0000-00-00');

-- --------------------------------------------------------

--
-- Table structure for table `shelves`
--

CREATE TABLE IF NOT EXISTS `shelves` (
  `ShelfId` int(10) NOT NULL,
  `ShelfName` varchar(255) NOT NULL,
  `BookId` int(10) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `shelves`
--

INSERT INTO `shelves` (`ShelfId`, `ShelfName`, `BookId`) VALUES
(0, 'Art', 1),
(1, 'Science', 2),
(2, 'Sports', 3),
(3, 'Literature', 4),
(0, 'Art', 5),
(0, 'Art', 6),
(3, 'Literature', 7),
(2, 'Sports', 8),
(2, 'Sports', 9),
(1, 'Science', 10),
(0, 'Art', 11),
(1, 'Science', 12),
(3, 'Literature', 13),
(0, 'Art', 14);

-- --------------------------------------------------------

--
-- Table structure for table `users`
--

CREATE TABLE IF NOT EXISTS `users` (
  `userName` varchar(255) NOT NULL,
  `Password` varchar(255) NOT NULL,
  `Email` varchar(255) NOT NULL,
  `Phone` int(10) NOT NULL,
  `Librarian` tinyint(4) NOT NULL,
  `FirstName` varchar(255) NOT NULL,
  `LastName` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `users`
--

INSERT INTO `users` (`userName`, `Password`, `Email`, `Phone`, `Librarian`, `FirstName`, `LastName`) VALUES
('admin', '21232f297a57a5a743894a0e4a801fc3', 'btholmes@iastate.edu', 1231231234, 1, 'admin', 'admin'),
('user', 'ee11cbb19052e40b07aac0ca060c23ee', 'btholmes@iastate.edu', 1231231234, 0, 'user', 'user');

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
