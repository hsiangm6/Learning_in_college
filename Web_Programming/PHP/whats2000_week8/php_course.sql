-- phpMyAdmin SQL Dump
-- version 5.1.1
-- https://www.phpmyadmin.net/
--
-- 主機： 127.0.0.1
-- 產生時間： 2022-11-18 15:38:08
-- 伺服器版本： 10.4.22-MariaDB
-- PHP 版本： 8.1.2

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- 資料庫: `php_course`
--

-- --------------------------------------------------------

--
-- 資料表結構 `account`
--

CREATE TABLE `account` (
  `STUID` text NOT NULL,
  `PassWord` text NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- 傾印資料表的資料 `account`
--

INSERT INTO `account` (`STUID`, `PassWord`) VALUES
('B104020001', '123456789'),
('B104020002', '987654321');

-- --------------------------------------------------------

--
-- 資料表結構 `member`
--

CREATE TABLE `member` (
  `mid` int(11) NOT NULL,
  `acc` varchar(20) NOT NULL,
  `pass` varchar(20) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- 傾印資料表的資料 `member`
--

INSERT INTO `member` (`mid`, `acc`, `pass`) VALUES
(1, 'abc', 'abcde'),
(2, 'acc2', 'pass2'),
(3, 'acc3', 'pass3'),
(7, '123', '123'),
(8, '1223', '12213');

-- --------------------------------------------------------

--
-- 資料表結構 `photo`
--

CREATE TABLE `photo` (
  `pid` int(11) NOT NULL,
  `mid` int(11) NOT NULL,
  `src` varchar(100) NOT NULL,
  `title` text NOT NULL,
  `description` varchar(500) NOT NULL,
  `hidden` tinyint(1) NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- 傾印資料表的資料 `photo`
--

INSERT INTO `photo` (`pid`, `mid`, `src`, `title`, `description`, `hidden`) VALUES
(1, 7, 'https://getbootstrap.com/docs/5.1/assets/img/bootstrap-icons.png', 'Test1', 'For test usage', 0),
(2, 7, 'https://getbootstrap.com/docs/5.1/assets/img/bootstrap-icons.png', 'Test2', 'For test usage', 0),
(3, 7, 'https://getbootstrap.com/docs/5.1/assets/img/bootstrap-icons.png', 'Test3', 'For test usage', 0),
(4, 7, 'https://getbootstrap.com/docs/5.1/assets/img/bootstrap-icons.png', 'Test4', 'For test usage', 0);

-- --------------------------------------------------------

--
-- 資料表結構 `student`
--

CREATE TABLE `student` (
  `STUID` varchar(9) NOT NULL,
  `name` varchar(20) NOT NULL,
  `birthdate` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- 傾印資料表的資料 `student`
--

INSERT INTO `student` (`STUID`, `name`, `birthdate`) VALUES
('B04402001', 'Amy', '2022-03-22'),
('B04402002', 'Joy', '2022-03-01'),
('B04402003', 'Catie', '2022-03-30'),
('B04402004', 'Anna', '2000-05-28'),
('B04402005', 'Bill', '2022-03-09'),
('B04402006', 'John', '2022-03-03');

--
-- 已傾印資料表的索引
--

--
-- 資料表索引 `member`
--
ALTER TABLE `member`
  ADD PRIMARY KEY (`mid`);

--
-- 資料表索引 `photo`
--
ALTER TABLE `photo`
  ADD PRIMARY KEY (`pid`);

--
-- 資料表索引 `student`
--
ALTER TABLE `student`
  ADD PRIMARY KEY (`STUID`);

--
-- 在傾印的資料表使用自動遞增(AUTO_INCREMENT)
--

--
-- 使用資料表自動遞增(AUTO_INCREMENT) `member`
--
ALTER TABLE `member`
  MODIFY `mid` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=9;

--
-- 使用資料表自動遞增(AUTO_INCREMENT) `photo`
--
ALTER TABLE `photo`
  MODIFY `pid` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
