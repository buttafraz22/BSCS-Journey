using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using EZInput;
using SpaceInvaders;

namespace Pong
{
    public partial class frmPong : Form
    {
        internal string directionBall;
        private string modeOfPlay;
        private int sum = 0;
        private PictureBox picPlay1;
        private PictureBox picPlay2;
        private PictureBox picBall;
        private PictureBox picPill;
        private int whichPlayer;
        bool isPillAlreadyPresent;
        Random rnd = new Random();
        public frmPong(string modeOfPlay)
        {
            InitializeComponent();
            directionBall = "UpDiagonal";
            this.modeOfPlay = modeOfPlay;
            isPillAlreadyPresent = false;
            whichPlayer = 3;
        }

        private void frmPong_Load(object sender, EventArgs e)
        {
            startGame();
        }

        private void timeGame_Tick(object sender, EventArgs e)
        { 
            if (modeOfPlay == "COMPUTER" || modeOfPlay == "1v1")
            {

                moveBall(picBall, directionBall);
                addPillintoGame();
               
                    if (Keyboard.IsKeyPressed(Key.UpArrow))
                    {
                        movePlayerUp(picPlay1);
                    }
                    if (Keyboard.IsKeyPressed(Key.DownArrow))
                    {
                        movePlayerDown(picPlay1);
                    }
                if (modeOfPlay != "1v1")
                {
                    if (directionBall == "UpDiagonal")
                    {
                        movePlayerUp(picPlay2); ;
                    }
                    if (directionBall == "BottomDiagonal")
                    {
                        movePlayerDown(picPlay2);
                    }
                }
                else
                {
                    if (Keyboard.IsKeyPressed(Key.A))
                    {
                        movePlayerUp(picPlay2);
                    }
                    if (Keyboard.IsKeyPressed(Key.Z))
                    {
                        movePlayerDown(picPlay2);
                    }
                }
                if((picBall.Bounds.IntersectsWith(picPlay2.Bounds)) && directionBall == "UpDiagonal")
                {
                    directionBall = "LeftDn";
                    int player1Score = Convert.ToInt32(lblPlayer2.Text);
                    player1Score += 10;
                    lblPlayer2.Text = player1Score.ToString();
                    whichPlayer = 1;
                }
                if ((picBall.Bounds.IntersectsWith(picPlay2.Bounds)) && directionBall == "BottomDiagonal")
                {
                    directionBall = "LeftUp";
                    int player1Score = Convert.ToInt32(lblPlayer2.Text);
                    player1Score += 10;
                    lblPlayer2.Text = player1Score.ToString();
                    whichPlayer = 1;
                }
                if ((picBall.Bounds.IntersectsWith(picPlay1.Bounds)) && directionBall == "LeftUp")
                {
                    directionBall = "UpDiagonal";
                    int player1Score = Convert.ToInt32(lblplayer1.Text);
                    player1Score += 10;
                    lblplayer1.Text = player1Score.ToString();
                    whichPlayer = 0;
                }
                if ((picBall.Bounds.IntersectsWith(picPlay1.Bounds)) && directionBall == "UpDiagonal")
                {
                    directionBall = "BottomDiagonal";
                    int player1Score = Convert.ToInt32(lblplayer1.Text);
                    player1Score += 10;
                    lblplayer1.Text = player1Score.ToString();
                    whichPlayer = 0;
                }
                //else if(picBall.Left <= 0)
                //{
                //    progressBar1.Value -= 1;
                //    if(progressBar1.Value == 0)
                //    {
                //        MessageBox.Show("Game Over");
                //        toStartOrCancel();
                //    }
                //}
                if(picBall.Bounds.IntersectsWith(picPill.Bounds) && whichPlayer == 0)
                {
                    int player1Score = Convert.ToInt32(lblplayer1.Text);
                    player1Score += 10;
                    lblplayer1.Text = player1Score.ToString();
                    this.Controls.Remove(picPill);
                    isPillAlreadyPresent = false;
                }
                if (picBall.Bounds.IntersectsWith(picPill.Bounds) && whichPlayer == 1)
                {
                    int player1Score = Convert.ToInt32(lblPlayer2.Text);
                    player1Score += 10;
                    lblPlayer2.Text = player1Score.ToString();
                    this.Controls.Remove(picPill);
                    isPillAlreadyPresent = false;
                }
                if (picBall.Left + picBall.Width > this.Width)
                {
                    directionBall = "LeftUp";
                }
                 if(picBall.Left < 0)
                {
                    directionBall = "BottomDiagonal";
                }

                if(Convert.ToInt32(lblPlayer2.Text) >= 100 || Convert.ToInt32(lblplayer1.Text) >= 100)
                {
                    sum = 20;
                    this.Text = "Level 2";
                    sum = 20;
                }
                if (Keyboard.IsKeyPressed(Key.Escape))
                {
                    toStartOrCancel();
                }
            }
           
        }
        private void toStartOrCancel()
        {
            this.Hide();
            Form frm = new FormGameStart();
            DialogResult dg = frm.ShowDialog();
            if (dg == DialogResult.Yes)
            {
                startGame();
                modeOfPlay = "COMPUTER";
            }
            else
            {
                startGame();
                modeOfPlay = "1v1";
            }
        }

        private void lblplayer1_Click(object sender, EventArgs e)
        {

        }
        private void movePlayerUp(PictureBox p)
        {
            if (p.Top > 0)
            {
                p.Top -= 10;// decrement of 10 corresponding to bounds of if condition
            }
        }
        private void movePlayerDown(PictureBox p)
        {
            if (p.Top + p.Height <= this.Height - 60) // just above the bottom of the form
            {
                p.Top += 10;
            }
        }
        private void moveRightDiagonalUp(PictureBox p)
        {
            if (directionBall == "UpDiagonal")
            {
                p.Top -= 10;
                p.Left += 10;
                // MessageBox.Show(p.Top.ToString());
                if (p.Top < 0) // just above the bottom of the form
                {
                    directionBall = "BottomDiagonal";
                }
                sum++;
                if(sum == 10)
                {
                    sum = 0;
                }
            }
        }
        private void moveBall(PictureBox p, string direction)
        {
            if (direction == "UpDiagonal")
            {
                moveRightDiagonalUp(p);
            }
            else if (direction == "BottomDiagonal")
            {
                moveRightDiagonalDn(p);
            }
            else if (direction == "LeftUp")
            {
                moveAntiDiagonalUp(p);
            }
            else if (direction == "LeftDn")
            {
                moveAntiDiagonalDn(p);
            }
        }

        private void moveRightDiagonalDn(PictureBox p)
        {
            if (directionBall == "BottomDiagonal")
            {
                p.Top += 10 ;
                p.Left += 10;
                if (p.Top + p.Height > this.Height)
                {
                    directionBall = "UpDiagonal";
                }
                sum++;
                if (sum == 10)
                {
                    sum = 0;
                }
            }
        }
        private void moveAntiDiagonalUp(PictureBox p)
        {
            if (directionBall == "LeftUp")
            {
                p.Top -= 10;
                p.Left -= 10;
                if (p.Top < 0) // just above the bottom of the form
                {
                    directionBall = "LeftDn";
                }
                sum++;
                if (sum == 10)
                {
                    sum = 0;
                }
            }
        }
        private void moveAntiDiagonalDn(PictureBox p)
        {
            if (directionBall == "LeftDn")
            {
                p.Top += 10;
                p.Left -= 10;
                if (p.Top + p.Height > this.Height)
                {
                    directionBall = "LeftUp";
                }
                sum++;
                if (sum == 10)
                {
                    sum = 0;
                }
            }
        }
        private void startGame()
        {
            picPlay1 = new PictureBox();
            Image img1 = SpaceInvaders.Properties.Resources.floor_arrow;
            picPlay1.Image = img1;
            picPlay1.BackColor = Color.Transparent;
            picPlay1.Width = img1.Width + 50;
            picPlay1.Height = img1.Height + 100;
            picPlay1.Top = rnd.Next(0, this.Height - picPlay1.Height) ;
            picPlay1.Left = -5;
            

            // for player 2
            picPlay2 = new PictureBox();
            Image img = SpaceInvaders.Properties.Resources.floor_arrow;
            picPlay2.Image = img;
            picPlay2.BackColor = Color.Transparent;
            picPlay2.Width = img.Width + 50;
            picPlay2.Height = img.Height + 100;
            picPlay2.Top = rnd.Next(0, this.Height - picPlay2.Height);
            picPlay2.Left = this.Width - 40;
            

            // for ball

            picBall = new PictureBox();
            Image img3 = SpaceInvaders.Properties.Resources.barrel;
            picBall.Image = img3 ;
            picBall.BackColor = Color.Transparent;
            picBall.Height = img3.Height;
            picBall.Width = img3.Width;
            picBall.Top = 120;
            picBall.Left = 120 ;

            // adding controls into system

            this.Controls.Add(picPlay1);
            this.Controls.Add(picPlay2);
            this.Controls.Add(picBall);
            this.BackColor = Color.Yellow;

            sum = 0;
            isPillAlreadyPresent = false;
            whichPlayer = 3;
        }
        private void addPillintoGame()
        {
            if (!isPillAlreadyPresent)
            {
                isPillAlreadyPresent = true;
                picPill = new PictureBox();
                Image img = SpaceInvaders.Properties.Resources.pills;
                picPill.Image = img;
                picPill.Width = img.Width;
                picPill.Height = img.Height;
                picPill.Top = rnd.Next(150,this.Height - 50);
                picPill.Left = rnd.Next(150, this.Width - 50);
                this.Controls.Add(picPill);
            }
        }

        private void progressBar2_Click(object sender, EventArgs e)
        {

        }
    }
}

