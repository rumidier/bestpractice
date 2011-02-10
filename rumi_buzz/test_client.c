#include <stdio.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

static void
error_message (char *message);

int
main (int   argc,
      char *argv[])
{
  int opt;
  int sock;
  int client_option;
  int port_option;
  int port_num;
  char *ip_num;
  struct sockaddr_in serv_adr;

  client_option = 0;
  port_option = 0;
  port_num = 0;
  //memset (get_buf_message, 0, strlen (get_buf_message));

  if (argc < 3)
    {
      printf ("Usage : %s -c <ip_num> -p <port> \n", argv[0]);
      exit (EXIT_FAILURE);
    }

  while ((opt = getopt (argc, argv, "c:p:")) != -1)
    {
      switch (opt)
        {
        case 'c':
          client_option = 1;
          ip_num = optarg;
          break;
        case 'p':
          port_option = 1;
          port_num = atoi (optarg);
          break;
        }
    }



  if (client_option == 1)
    {
      /**
       * 서버와 연결 되면 client_option 참 이라면 활성화 된다.
       * 1. 소켓을 활성화 시키고 소켓이 활성화가 안돼면 메세지 출력후 종료한다.
       * 2. 연결된 소켓을 확인하여 연결한다.
       * 3. 연결이 되면 명령어를 읽어 들인다.
       */
      char *explan_message;
      char buf_message[256];
      char get_buf_message[256];
      char *message_full_string = NULL;
      int get_message_len;
      int str_len;

      memset (buf_message, 0, 256);
      explan_message = (char *) malloc (sizeof (char) * 256);

      sock = socket (PF_INET, SOCK_STREAM, 0);

      if (sock == -1)
        error_message ("socket() error!");
      memset (&serv_adr, 0, sizeof (serv_adr));

      serv_adr.sin_family = AF_INET;
      serv_adr.sin_addr.s_addr = inet_addr (ip_num);
      serv_adr.sin_port = htons (port_num);

      if (connect (sock, (struct sockaddr *) &serv_adr, sizeof (serv_adr)) == -1)
        error_message ("connect error!");
      else
        {
          puts ("Connected.....!\n");

          fputs ("Input message (Q to quit) : \n", stdout);
          memset (get_buf_message, 0, strlen (get_buf_message));
          fgets (get_buf_message, 256, stdin);

          get_message_len = strlen (get_buf_message); 
          message_full_string = (char *) realloc (message_full_string, sizeof (char) * get_message_len);
          strcat (message_full_string, get_buf_message);

          int check_n = 0;

          if (get_message_len == 2 && get_buf_message[0] == 'Q')
            {
              printf ("종료 합니다\n");
              return 0;
            }

          if (get_buf_message[get_message_len - 1]  == '\n')
            {
              memset (get_buf_message, 0, 256);
            }
          else
            {
              while (1)
                {
                  memset (get_buf_message, 0, get_message_len);
                  fgets (get_buf_message, 256, stdin);

                  get_message_len = strlen (get_buf_message); 
                  message_full_string = (char *) realloc (message_full_string, sizeof (char) * (get_message_len + (strlen (message_full_string))));
                  strcat (message_full_string, get_buf_message);

                  if (get_buf_message[get_message_len - 1]  == '\n')
                    {
                      memset (get_buf_message, 0, get_message_len);
                      break;
                    }
                  check_n++;
                }
            }
        }
      memset (get_buf_message, 0, strlen (get_buf_message));
      write (sock, message_full_string, strlen (message_full_string));
      str_len = 0;

      str_len = read (sock, buf_message, 254);

      if (str_len > 0)
        {
          strcat (explan_message, buf_message);

          if (buf_message[str_len - 1]  == '\n')
            {
              memset (buf_message, 0, 256);
            }
          else
            {
              while (1)
                {
                  read (sock, buf_message, 256);
                  str_len += strlen (buf_message);
                  explan_message = (char *) realloc (explan_message, (sizeof (char) * (str_len)));
                  strcat (explan_message, buf_message);

                  if (buf_message[strlen (buf_message) - 1] == '\n')
                    break;
                  memset (buf_message, 0, strlen (buf_message));
                }

              printf ("%s", explan_message);
              get_message_len = 0;
              memset (explan_message, 0, sizeof (explan_message));
              memset (buf_message, 0, strlen (buf_message));
              memset (message_full_string, 0, sizeof (message_full_string));
              close (sock);
            }
        }
    }
  else
    {
      printf ("dic file start\n");
    }

  return 0;
}

static void
error_message (char *message)
{
  fputs (message, stderr);
  fputc ('\n', stderr);
  exit (EXIT_FAILURE);
}
