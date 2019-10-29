CC = g++
CCFLAGS = -Wall
PRJ = DungeonsLinux
OBJS = DungeonsLinux.o screen.o room.o entity.o player.o enemy.o armour.o weapon.o chest.o battle.o worldClass.o factoryClass.o potion.o
HEAD = screen.h screenElement.h player.h enemy.h room.h item.h armour.h weapon.h chest.h battle.h worldClass.h factoryClass.h potion.h

$(PRJ): $(OBJS)
	$(CC) $(OBJS) -o $(PRJ)

%.o : %.cc
	$(CC) -c $(CCFLAGS) $<

$(OBJS):$(HEAD)

.PHONY: clean
clean: ## next lines must begin with a TAB                                                                                                                                                                                                                                    
	rm -f $(OBJS) $(PRJ)
	rm -f *~ *% *# .#*
